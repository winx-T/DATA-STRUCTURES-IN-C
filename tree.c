#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Preorder traversal function NLR
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit the root
        preorder(root->left);      // Traverse the left subtree
        preorder(root->right);     // Traverse the right subtree
    }
}

// Inorder traversal function LNR
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Traverse the left subtree
        printf("%d ", root->data);  // Visit the root
        inorder(root->right);     // Traverse the right subtree
    }
} 
// Postorder traversal function LRN
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);      // Traverse the left subtree
        postorder(root->right);     // Traverse the right subtree
        printf("%d ", root->data);  // Visit the root
    }
}
// Function to search for a value in a binary search tree
void search(struct Node* root, int val) {
    if (root == NULL) {
        printf("Value not found\n");
        return;
    }
    if (root->data == val) {
        printf("%d Value found\n", val);
        return;
    }
    else if (val < root->data) {
        search(root->left, val);  // Continue searching in the left subtree
    }
    else {
        search(root->right, val);  // Continue searching in the right subtree
    }
}

// Function to insert a value in a binary search tree
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);  // Update left child
    } else {
        root->right = insert(root->right, val);  // Update right child
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n*1. Insert\n*2. Search\n*3. Preorder\n*4. Inorder\n*5. Postorder\n*6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}