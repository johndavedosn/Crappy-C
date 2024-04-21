#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define null NULL
typedef struct {
    char *string;
    int length;
    int capacity;
} String;

String *new_string(char *str){
    
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    str -= length; 
    
    String *s = (String *)malloc(sizeof(String));
    if (s == null) {
        perror("String memory allocation failed");
        return null; 
    }

    
    s->string = (char *)malloc((length + 1) * sizeof(char)); 
    if (s->string == null) {
        perror("String memory allocation failed");
        free(s); 
        return null; 
    }
    strcpy(s->string, str);

    
    s->length = length;
    s->capacity = length + 6; 

    return s; 
}
void replace(String *str, char char_to_rep, char new_char) {
    for (int i = 0; i < str->length; i++) {
        if (str->string[i] == char_to_rep) {
            str->string[i] = new_char;
            return;
        }
    }
    fprintf(stderr, "The given character was not found.\n");
}
void add_character(String *str, char c) {
    str->string = (char *)realloc(str->string, str->capacity);
    if (str->string == NULL) {
        perror("String memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    str->string[str->length] = c;
    str->length++;
    str->capacity = str->length + 6;
    str->string[str->length] = '\0';
}
void remove_character(String *str, char char_to_remove) {
    int read_ptr = 0;  
    int write_ptr = 0; 
    
    
    while (read_ptr < str->length) {
        
        
        if (str->string[read_ptr] != char_to_remove) {
            str->string[write_ptr] = str->string[read_ptr];
            write_ptr++;
        }
        read_ptr++; 
    }
    
    
    str->length = write_ptr;
    
    
    str->string[write_ptr] = '\0';
    
    
    
}

int main() {
    String *str = new_string("Hello world");
    add_character(str, '!');
    printf("%s\n", str->string);
    printf("%d\n", str->length);
    printf("%d\n", str->capacity);
    replace(str, '!', '.');
    printf("%s\n", str->string);
    remove_character(str, '.');
    printf("%s\n", str->string);

}