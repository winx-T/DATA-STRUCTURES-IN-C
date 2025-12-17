#include <stdio.h>
#include <stdlib.h>

/**
 * @file Single Linked List.c
 */


/**
 --> Creating the Node of a single linked list
 *
 * @struct node
 * @description
 * This structure represents a single node in a singly linked list.
 * Each node stores:
 * - `data`: An integer value that holds the data for the node.
 * - `link`: A pointer to the next node in the linked list.
 *           If the node is the last node, this pointer will be `NULL`.
 */

struct node {
    int data;
    struct node *link;
};

/*Traversing a Single Linked List */

    /**
     --> Method 1: By Counting the number of Nodes

      * @function count_of_nodes
      * @description
      * This function counts the number of nodes in a singly linked list.
      * It starts from the head node and traverses the list, incrementing
      * a counter for each node. If the list is empty (head is NULL),
      * it prints a message indicating that the list is empty. After
      * traversing the list, the function prints the total number of nodes.
      *
      * @param head: A pointer to the head node of the linked list.
    */

     void count_of_nodes(struct node *head){
         int count = 0;
         if (head == NULL) {
             printf("Linked List is empty\n");
             return;
         }
         struct node *ptr = head;
         while (ptr != NULL) {
             count++;
             ptr = ptr->link;
         }
         printf("Number of nodes are: %d\n", count);
     }
   /**
    -->Method 2: By Printing the Data

      * @function print_data
      * @description
      * This function prints the data stored in each node of a singly linked list.
      * It starts from the head node and traverses the list, printing the `data`
      * field of each node. If the list is empty (head is NULL), it prints a
      * message indicating that the list is empty. The function then moves to
      * the next node by following the `link` pointer until it reaches the end of the list.
      *
      * @param head: A pointer to the head node of the linked list.
    */

     void print_data(struct node *head){
         if (head == NULL) {
           printf("Linked List is empty\n");
             return;
         }
         printf("This is the List data:\n");
         struct node *ptr = head;
         while (ptr != NULL) {
             printf("\t %d", ptr->data);
             ptr = ptr->link;
         }
     }

     /**
 -->Insertion at the Beginning of the list

  * @function add_beg
  * @description
  * This function inserts a new node at the beginning of a singly linked list.
  * The new node is created dynamically with the specified data, and it is
  * linked as the first node in the list by updating the `link` pointer of the
  * original head node. If the memory allocation for the new node fails,
  * an error message is displayed, and the function terminates early.
  * The function assumes the list is not empty and that the head pointer
  * points to the first node of the linked list.
  *
  * @param head: A pointer to the head node of the linked list.
  * @param x: The integer value to be stored in the new node.
*/
void add_beg(struct node** head, int x) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node-> data= x;
     new_node->link = NULL;

    new_node->link = *head;  // Link new node to the current head
    *head = new_node;        // Update the original head
}


/**
 -->Insertion at the End of the list

  * @function add_at_end
  * @description
  * This function inserts a new node at the end of a singly linked list.
  * The new node is created dynamically with the specified data, and it is
  * linked as the last node in the list by updating the `link` pointer of
  * the current last node. If the memory allocation for the new node fails,
  * an error message is displayed, and the function terminates early.
  * The function assumes the list is not empty and that the head pointer
  * points to the first node of the linked list.
  *
  * @param head: A pointer to the head node of the linked list.
  * @param x: The integer value to be stored in the new node.
*/

void add_at_end(struct node **head, int x) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = x;
    new_node->link = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

/**
 --> Function to insert a node before a specific element
 * @function insert_before_element
 * @description
 * This function inserts a new node before a specific element in a singly linked list.
 *
 * The function performs the following steps:
 * 1. Prompts the user to enter the data for the new node and the value before which the new node will be inserted.
 * 2. Allocates memory for the new node and initializes its data field.
 * 3. Checks if the list is empty. If it is, a message is printed, and the function returns.
 * 4. If the target value is the first node, the new node is inserted at the beginning.
 * 5. Traverses the list to find the target value.
 * 6. If the target value is not found, a message is printed, and the function returns.
 * 7. Inserts the new node before the target value by adjusting the pointers.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void insert_before_element(struct node **head) {
    struct node *new_node, *ptr, *preptr = NULL;
    int num, val;
    printf("\n Enter the data field: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the new data will be inserted: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = num;
    new_node->link = NULL;

    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty, cannot insert before %d\n", val);
        free(new_node);
        return;
    }

    ptr = *head;
    // Check if the value is the first node
    if (ptr->data == val) {
        new_node->link = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the target value
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->link;
    }

    // If the target value is not found
    if (ptr == NULL) {
        printf("Target element not found\n");
        free(new_node);
        return;
    }

    // Insert the new node before the target value
    preptr->link = new_node;
    new_node->link = ptr;
}

/**
-->Insertion at any position of the list
 * @function insert_at_position
 * @description
 * This function inserts a new node at a specific position in a singly linked list.
 * It starts from the head node and traverses the list until the desired position is reached.
 * If the position is valid (1-based index), the new node is inserted at that position by adjusting the pointers.
 * If the position is invalid (less than 1 or greater than the number of nodes), an error message is displayed.
 *
 * @param head: A pointer to the head node of the linked list.
 * @param x: The integer value to be stored in the new node.
 * @param position: The position at which to insert the new node (1-based index).
 */
void insert_at_position(struct node** head, int x, int position) {
    // Create a new node
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = x;
    new_node->link = NULL;

    // If position is 1, insert at the beginning
    if (position == 1) {
        new_node->link = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the node just before the specified position
    struct node* current = *head;
    int count = 1;

    while (current != NULL && count < position - 1) {
        current = current->link;
        count++;
    }

    // If the position is invalid (greater than the number of nodes)
    if (current == NULL) {
        printf("Invalid position\n\n");
        free(new_node); // Free memory if position is invalid
        return;
    }

    // Insert the new node at the specified position
    new_node->link = current->link;
    current->link = new_node;
}


/**
--> Function to delete a node at the beginning
 * @function delete_beg
 * @description
 * This function deletes the first node of a singly linked list.
 *
 * The function performs the following steps:
 * 1. Checks if the list is empty. If it is, a message is printed, and the function returns.
 * 2. If the list is not empty, it removes the head node:
 *    - A temporary pointer is used to store the current head.
 *    - The head pointer is updated to point to the second node in the list.
 *    - The memory occupied by the original head node is freed.
 * 3. A success message is printed upon deletion of the node.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void delete_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->link;
    free(temp);
    printf("Node at the beginning deleted\n");
}


/**
--> Function to delete a node at the end
 * @function delete_end
 * @description
 * This function deletes the last node of a singly linked list.
 *
 * The function performs the following steps:
 * 1. Checks if the list is empty. If it is, a message is printed, and the function returns.
 * 2. If the list contains only one node, that node is deleted, and the head pointer is set to `NULL`.
 * 3. For lists with more than one node:
 *    - Traverses the list to find the second-to-last node.
 *    - Frees the memory of the last node and sets the `link` of the second-to-last node to `NULL`.
 * 4. Prints a success message upon deletion.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void delete_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node *current = *head;
    if (current->link == NULL) {
        free(current);
        *head = NULL;
        printf("Node at the end deleted\n");
        return;
    }
    while (current->link->link != NULL) {
        current = current->link;
    }
    free(current->link);
    current->link = NULL;
    printf("Node at the end deleted\n");
}

/**
--> Function to delete a specific element
 * @function delete_element
 * @description
 * This function deletes the first occurrence of a specific element in a singly linked list.
 *
 * The function performs the following steps:
 * 1. Checks if the list is empty. If it is, a message is printed, and the function returns.
 * 2. If the element is in the head node, it updates the head pointer and frees the memory of the node.
 * 3. For elements not at the head:
 *    - It traverses the list to find the node with the specified element.
 *    - If the element is not found, it prints an error message.
 * 4. Deletes the node containing the specified element by adjusting the `link` of the previous node.
 * 5. Prints a success message indicating the element that was deleted.
 *
 * @param head: A double pointer to the head node of the linked list.
 * @param element: The element to delete from the list.
 */
void delete_element(struct node **head, int element) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;

    // If the element is in the head node
    if (temp != NULL && temp->data == element) {
        *head = temp->link;
        free(temp);
        printf("Element %d deleted from the list\n", element);
        return;
    }

    // Search for the element to be deleted
    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->link;
    }

    // If the element was not present in the list
    if (temp == NULL) {
        printf("Element %d not found in the list\n", element);
        return;
    }

    // Unlink the node from the linked list
    prev->link = temp->link;
    free(temp);
    printf("Element %d deleted from the list\n", element);
}

/**
--> Function to delete the entire linked list
 * @function delete_entire_list
 * @description
 * This function deletes all nodes in a singly linked list, effectively clearing the entire list.
 *
 * The function performs the following steps:
 * 1. Initializes a pointer `current` to the head of the list and a `next` pointer to assist in node traversal.
 * 2. Iterates through the list:
 *    - For each node, it stores the pointer to the next node in `next`.
 *    - Frees the memory occupied by the current node.
 *    - Moves to the next node using the `next` pointer.
 * 3. After the loop, the head pointer is set to `NULL` to indicate the list is empty.
 * 4. Prints a success message.
 *
 * @param head: A double pointer to the head node of the linked list.
 */
void delete_entire_list(struct node **head) {
    struct node *current = *head;
    struct node *next;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }

    *head = NULL;
    printf("Entire list deleted\n");
}

/**
--> Function to reverse the linked list
 * @function arrange_list
 * @description
 * This function sorts a singly linked list in ascending order using the bubble sort algorithm.
 *
 * The function performs the following steps:
 * 1. It checks if the list is empty or contains only one node. In these cases, the list is already "arranged" (sorted).
 * 2. It uses two pointers, `i` and `j`, to traverse the list and compare the values of the nodes.
 * 3. If `i->data` is greater than `j->data`, it swaps the values of the two nodes.
 * 4. The list is repeatedly traversed to ensure that the smallest elements "bubble" to the beginning of the list.
 * 5. After sorting, a message is printed indicating that the list has been arranged in order.
 *
 * @pparam head: A pointer to the head node of the linked list.
 */
void arrange_list(struct node **head) {
    if (*head == NULL || (*head)->link == NULL) {
        return; // List is empty or has only one node
    }

    struct node *i, *j;
    int temp;

    for (i = *head; i->link != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List arranged in order\n");
}

/**
--> Function to search for an element in the list
 * @function search_list
 * @description
 * This function searches for a specific element (key) in a singly linked list.
 *
 * The function performs the following steps:
 * 1. Initializes a pointer `current` to the head of the list and a variable `position` to track the position of the current node.
 * 2. Iterates through the list:
 *    - If the data in the current node matches the key, it prints the position where the element was found and returns.
 *    - If the data does not match, it moves to the next node and increments the position counter.
 * 3. If the end of the list is reached without finding the key, it prints a message indicating the element was not found.
 *
 * @param head: A pointer to the head node of the linked list.
 * @param key: The element to search for in the list.
 */void search_list(struct node *head, int key) {
    struct node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        current = current->link;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}


/**
 * The MAIN function
 */


int main() {
    /* Allocate memory for the head node */
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    /* Allocate memory for the second node */
    struct node *current = malloc(sizeof(struct node));
    current->data = 50;
    current->link = NULL;
    head->link = current;

    /* Allocate memory for the third node */
    current = malloc(sizeof(struct node));
    current->data = 74;
    current->link = NULL;
    head->link->link = current;

    /* Print the data of each node */
    printf("%d\n", head->data);
    printf("%d\n", head->link->data);
    printf("%d\n\n", head->link->link->data);

    /* Call the count_of_nodes function */
    count_of_nodes(head);
     printf("\n");
    add_at_end(&head,132);
    print_data(head);
     printf("\n");
    /*Insertion at the End of the list*/
    add_at_end(head,132);

    /*Insertion at the Biginning of the list*/
    add_beg(&head, 19);

    // Insert a node at position 2
    insert_at_position(&head, 99, 2);

    /* Printing the Data by calling the print_data function */
    print_data(head);



     printf("\n\n");
     int choice, x, element, position;
    while (1) {
        printf("\n\t******* Choose an option: **********\n");
        printf("\t* 1. insert data at the beginning\n");
        printf("\t* 2. insert data at the end\n");
        printf("\t* 3. Insert before a specific element \n");
        printf("\t* 4. insert data at a specific position \n");
        printf("\t* 5. Delete data at the beginning\n");
        printf("\t* 6. Delete data at the end\n");
        printf("\t* 7. Delete a specific data\n");
        printf("\t* 8. Delete the entire list\n");
        printf("\t* 9. Search for an element \n");
        printf("\t* 10. Arrange the list\n");
        printf("\t* 11. Print the list\n");
        printf("\t* 12. count the list elements number\n");
        printf("\t* 13. Exit\n");
        printf("\t**************************************\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
           case 1:
                printf("Enter data to add at the beginning: ");
                scanf("%d", &x);
                add_beg(&head, x);
                break;
            case 2:
                printf("Enter data to add at the end: ");
                scanf("%d", &x);
                add_at_end(&head, x);
                break;
            case 3:
                insert_before_element(&head);
                break;
            case 4:
                printf("Enter data to add: ");
                scanf("%d", &x);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(&head, x, position);
                break;
            case 5:
                delete_beg(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &element);
               delete_element(&head, element);
                break;
            case 8:
                delete_entire_list(&head);
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search_list(head, x);
                break;
            case 10:
                arrange_list(&head);
                break;
            case 11:
                print_data(head);
                break;
            case 12:
                count_of_nodes(head);
                break;
            case 13:
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

