#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp;

// Function to create a linked list
void createLinkedList() {
    head = NULL;
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;  // Initialize the new node's next pointer to NULL
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("Do you want to add values to the linked list (1/0): ");
        scanf("%d", &choice);
    }
    temp = head;
    printf("The linked list values are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
void insert_in_beginning() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

// Function to insert at the end
void insert_at_end() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to insert at a specific position
void insert_at_position() {
    int pos, i = 1;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos == 1) {
        insert_in_beginning();
    } else {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert at position %d: ", pos);
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp != NULL) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            printf("Position out of range\n");
        }
    }
}

// Main function
int main() {
    int option;
    createLinkedList();
    
    printf("\nWhere do you want to insert a new node?\n");
    printf("1. Beginning\n");
    printf("2. End\n");
    printf("3. Specific Position\n");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            insert_in_beginning();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_position();
            break;
        default:
            printf("Invalid option\n");
    }
    
    printf("\nUpdated Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}
