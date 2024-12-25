#include <stdio.h>
#include <stdlib.h>

/**
 * @file Double Linked List.c
 */

/**
 --> Creating the Node of a doubly linked list
 *
 * @struct node
 * @description
 * This structure represents a single node in a doubly linked list.
 * Each node stores:
 * - `data`: An integer value that holds the data for the node.
 * - `prev`: A pointer to the previous node in the linked list.
 * - `next`: A pointer to the next node in the linked list.
 */
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

/**
 --> Traversing a Doubly Linked List
 *
 * @function count_of_nodes
 * @description
 * This function counts the number of nodes in a doubly linked list.
 * It starts from the head node and traverses the list, incrementing
 * a counter for each node. If the list is empty (head is NULL),
 * it prints a message indicating that the list is empty. After
 * traversing the list, the function prints the total number of nodes.
 *
 * @param head: A pointer to the head node of the linked list.
 */
void count_of_nodes(struct node* head) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes: %d\n", count);
}

/**
 * @function print_data
 * @description
 * This function prints the data stored in each node of a doubly linked list.
 * It starts from the head node and traverses the list, printing the `data`
 * field of each node. If the list is empty (head is NULL), it prints a
 * message indicating that the list is empty. The function then moves to
 * the next node by following the `next` pointer until it reaches the end of the list.
 *
 * @param head: A pointer to the head node of the linked list.
 */
void print_data(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node* temp = head;
     printf("List data: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 --> Insertion at the Beginning of the List
 *
 * @function add_beg
 * @description
 * This function inserts a new node at the beginning of a doubly linked list.
 * The new node is created dynamically with the specified data, and it is
 * linked as the first node in the list by updating the `next` pointer of
 * the new node and the `prev` pointer of the original head node.
 *
 * @param head: A double pointer to the head node of the linked list.
 * @param data: The integer value to be stored in the new node.
 */
void add_beg(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

/**
 --> Insertion at the End of the List
 *
 * @function add_at_end
 * @description
 * This function inserts a new node at the end of a doubly linked list.
 * It traverses the list to the last node and updates the `next` pointer
 * of the last node and the `prev` pointer of the new node to insert it
 * at the end.
 *
 * @param head: A double pointer to the head node of the linked list.
 * @param data: The integer value to be stored in the new node.
 */
void add_at_end(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

/**
 --> Insertion at Any Position of the List
 *
 * @function insert_at_position
 * @description
 * This function inserts a new node at a specific position in a doubly linked list.
 * It traverses the list to find the correct position, then adjusts the `next` and
 * `prev` pointers of the relevant nodes to insert the new node.
 *
 * @param head: A double pointer to the head node of the linked list.
 * @param data: The integer value to be stored in the new node.
 * @param position: The position at which to insert the new node (1-based index).
 */
void insert_at_position(struct node** head, int data, int position) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;

    new_node->data = data;

    if (position == 1) {
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
}

void delete_by_value(struct node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    // Check if the head node itself holds the value
    if (temp->data == value) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse the list to find the node with the value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If value was not found
    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }

    // Adjust pointers to delete the node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}


/**
 --> Deletion at the Beginning of the List
 *
 * @function delete_beg
 * @description
 * This function deletes the first node of a doubly linked list.
 * It updates the `next` pointer of the head node and the `prev` pointer
 * of the second node (if it exists) to remove the first node.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void delete_beg(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

/**
 --> Deletion at the End of the List
 *
 * @function delete_end
 * @description
 * This function deletes the last node of a doubly linked list.
 * It traverses to the last node and updates the `next` pointer of
 * the second-to-last node to remove the last node.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void delete_end(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

/**
 --> Deletion at a Specific Position
 *
 * @function delete_at_position
 * @description
 * This function deletes a node at a specific position in a doubly linked list.
 * It adjusts the `next` and `prev` pointers of the neighboring nodes to remove
 * the specified node.
 *
 * @param head: A double pointer to the head node of the linked list.
 * @param position: The position of the node to delete (1-based index).
 */
void delete_at_position(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;
    free(temp);
}
void clear_list(struct node** head) {
    struct node* temp = *head;
    while (temp != NULL) {
        struct node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    *head = NULL;
}
void print_reverse(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Traverse to the last node
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print the list in reverse order
    printf("List in reverse: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/**
 --> Main Function
 */
int main() {
    struct node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n************ Menu ************\n");
        printf("* 1. Add at beginning\n");
        printf("* 2. Add at end\n");
        printf("* 3. Add at specific position\n");
        printf("* 4. Delete from beginning\n");
        printf("* 5. Delete from end\n");
        printf("* 6. Delete from specific position\n");
        printf("* 7. Count nodes\n");
        printf("* 8. Print list\n");
        printf("* 9. Delete by value\n");
        printf("* 12. Clear the list\n");
        printf("* 11. Print in reverse\n");
        printf("* 12. Exit\n");
        printf("*******************************\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                add_beg(&head, data);
                break;
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                add_at_end(&head, data);
                break;
            case 3:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                break;
            case 4:
                delete_beg(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 7:
                count_of_nodes(head);
                break;
            case 8:
                print_data(head);
                break;
            
            case 9:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                delete_by_value(&head, data);
                break;
            case 10:
                clear_list(&head);
                printf("List cleared.\n");
                break;
            case 11:
                print_reverse(head);
                break;
                case 12:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
