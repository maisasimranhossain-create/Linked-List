
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Creation of 3 nodes
void createThreeNodes() {
    struct Node *first, *second, *third;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;
}

// 2. Traversal
void traversal() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 3. Insertion at beginning
void insertAtBeginning(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// 4. Insertion at end
void insertAtEnd(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// 5. Deletion at beginning
void deleteAtBeginning() {
    if (head == NULL)
        return;

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// 6. Deletion at end
void deleteAtEnd() {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// 7. Insertion in the middle
void insertInMiddle(int pos, int value) {
    if (pos < 1)
        return;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 8. Deletion from the middle
void deleteFromMiddle(int pos) {
    if (head == NULL || pos < 1)
        return;

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// 9. Searching
int search(int key) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key)
            return pos;

        temp = temp->next;
        pos++;
    }

    return -1;
}

// 10. Reversing
struct Node* reverse(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Main function
int main() {
    createThreeNodes();

    printf("Initial Linked List:\n");
    traversal();

    printf("\nInsert 5 at beginning:\n");
    insertAtBeginning(5);
    traversal();

    printf("\nInsert 40 at end:\n");
    insertAtEnd(40);
    traversal();

    printf("\nInsert 25 at position 3:\n");
    insertInMiddle(3, 25);
    traversal();

    printf("\nSearch for 30:\n");
    int result = search(30);

    if (result != -1)
        printf("Element found at position %d\n", result);
    else
        printf("Element not found\n");

    printf("\nDelete at beginning:\n");
    deleteAtBeginning();
    traversal();

    printf("\nDelete at end:\n");
    deleteAtEnd();
    traversal();

    printf("\nDelete at position 2:\n");
    deleteFromMiddle(2);
    traversal();

    printf("\nReverse the Linked List:\n");
    head = reverse(head);
    traversal();

    return 0;
}
