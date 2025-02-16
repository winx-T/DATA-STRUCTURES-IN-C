#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Queue structure
struct queue {
    struct node* front;
    struct node* rear;
};

// Initialize the queue
void creation_file(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Enqueue operation
void insertion(struct queue* q, int x) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    printf("Enqueued %d to the queue\n", x);
}

// Dequeue operation
void supression(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty, nothing to dequeue\n");
        return;
    }

    struct node* temp = q->front;
    printf("Dequeued %d from the queue\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // Queue is empty
    }
    free(temp);
}

// Front operation
void front(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", q->front->data);
}

// Peek operation
int peek(struct queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    return q->front->data;
}

// IsEmpty operation
int is_queue_empty(struct queue* q) {
    return q->front == NULL;
}

// Function to free the queue
void free_queue(struct queue* q) {
    while (q->front != NULL) {
        supression(q); // Free each node
    }
}

int main() {
    // Declare and initialize the queue
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    creation_file(q);
    
    int val, option;
    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. INSERTION");
        printf("\n2. SUPPRESSION");
        printf("\n3. PEEK");
        printf("\n4. VIDER (Clear Queue)");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the number to insert into the queue: ");
                scanf("%d", &val);
                insertion(q, val);
                break;

            case 2:
                supression(q);
                break;

            case 3:
                val = peek(q);
                if (val != -1)
                    printf("\nThe front element of the queue is: %d\n", val);
                else
                    printf("\nQueue is empty\n");
                break;

            case 4:
                free_queue(q);
                printf("\nQueue has been cleared\n");
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 5);
    return 0;
}
