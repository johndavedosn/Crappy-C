#include <stdio.h>
#include <stdlib.h>
#define null NULL
typedef struct {
    void *next;
    int data;

} Node;
Node *head = null;
Node * addnode(int data) {
    Node* new = null;
    if (head == null) {
    new = (Node*)(malloc(sizeof(Node))); 
    if (new == null) {
        return null;
    }  
    new->data = data;
    head = new;
    new->next = null;
}
else {
    new = (Node*)(malloc(sizeof(Node))); 
    if (new == null) {
        return null;
    }  
    new->data = data;
    new->next = head;
    head = new;
}    
  return new;   
}
int removenode(int data) {
    Node* current = head;
    Node* prev = head;
    while (current != null) {
        if (current->data == data) {
            if (current == head){
                head = current->next;
            }
            else {
                prev->next = current->next;
                free(current);
                current = null;
            }
            return 1;

        }          
    prev = current;
    current = current->next;
    }
    return 0;
}

void printlist(){
    Node* current = head;
    while (current != null) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}
void printmenu() {
    printf("Main menu : \n");
    printf("1. Add a node \n");
    printf("2. Remove a node \n");
    printf("3. Print the list \n"); 
    printf("4. Exit \n");
    return;    
}

int main() {
    int option;
    while (option != 5){
        printmenu();
        int number_recv = scanf("%d", &option);
        if (number_recv == 1 && option > 0 && option <= 5){
            switch (option) {
                case 1: 
                // add
                printf("Wtf do I add to the list?\n");
                scanf("%d", &option);
                Node* new=  addnode(option);

                break;
                case 2:
                //remove
                printf("Whoa, What do you want to remove buddy?\n");
                scanf("%d", &option);
                int node_deleted = removenode(option);
                if (node_deleted == 1) {
                    printf("The node pooped outta existance\n");
                }
                else {
                    printf("What an unlitsening node \n");
                }

                break; 
                case 3:
                printlist();
                case 4: 
                break;
            }
        }
    }
    return 0;
    
}
