#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct stack {
    int data;
    struct stack *next;
};

// Global stack pointer
struct stack *top = NULL;

// Function to push an element onto the stack
void push(int val) {
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    ptr->next = top;
    top = ptr;
}

// Function to pop an element from the stack
void pop() {
    struct stack *ptr;
    if (top == NULL) {
        printf("\nPILE VIDE\n");
    } else {
        ptr = top;
        printf("\nLa valeur qui sera supprimée est : %d\n", ptr->data);
        top = top->next;
        free(ptr);
    }
}

// Function to view the top element of the stack
int peek() {
    if (top == NULL) {
        printf("\nPILE VIDE\n");
        return -1;
    } else {
        return top->data;
    }
}

// Main function
int main() {
    int val, option;

    do {
        printf("\n***** MENU PRINCIPAL *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. EXIT");
        printf("\nEntrer votre option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEntrer le nombre à empiler dans la pile : ");
                scanf("%d", &val);
                push(val);  // No need to return top
                break;

            case 2:
                pop();  // No need to return top
                break;

            case 3:
                val = peek();
                if (val != -1) {
                    printf("\nLa valeur au sommet de la pile est : %d\n", val);
                }
                break;

            case 4:
                printf("\nSortie du programme.\n");
                break;

            default:
                printf("\nOption invalide! Veuillez réessayer.\n");
        }
    } while (option != 4);

    return 0;
}
