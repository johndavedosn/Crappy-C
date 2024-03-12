#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int eax;
    int ecx;
    int ebx;
    int *edx;
} CPU;

void initCPU(CPU *cpu) {
    cpu->eax = 0;
    cpu->ecx = 0;
    cpu->ebx = 0;
    cpu->edx = NULL;
}

void resetCPU(CPU *cpu) {
    cpu->eax = 0;
    cpu->ecx = 0;
    cpu->ebx = 0;
    cpu->edx = NULL;
}

void syscall(CPU *cpu) {
    char *buff;

    switch (cpu->eax) {
        case 1: 
        // sys_exit
            exit(cpu->ebx);
            break;
        case 2: 
        // sys_stdout
            buff = (char *)malloc(cpu->ecx + 1);
            for (int i = 0; i < cpu->ecx; i++) {
                char c = cpu->edx[i];
                buff[i] = c;
            }
            buff[cpu->ecx] = '\0';  
            printf("%s\n", buff);   
            free(buff);
            break;
        case 3: 
        // sys_reset
            resetCPU(cpu);
            break;
        case 4: 
        // sys_stdin
            buff = (char *)malloc(cpu->ecx + 1);
            fgets(buff, cpu->ecx + 1, stdin);
            for (int i = 0; i < cpu->ecx; i++) {
                cpu->edx[i] = (int)buff[i];
            }
            break;
    }
}

int main() {
    CPU *cpu = (CPU *)malloc(sizeof(CPU));
    initCPU(cpu);
    cpu->eax = 4; 
    cpu->ecx = 10; 
    cpu->edx = (int *)malloc(cpu->ecx * sizeof(int)); 
    syscall(cpu);
    printf("Input: ");
    for (int i = 0; i < cpu->ecx; i++) {
        printf("%c", (char)cpu->edx[i]);
    }
    printf("\n");
    free(cpu->edx);
    free(cpu);
    return 0;
}
