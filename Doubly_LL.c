
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// 1. Creation of 3 nodes
void createThreeNodes() {
    struct Node *first, *second, *third;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    head = first;
    tail = third;
}

// 2. Forward traversal
void traverseForward() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// 3. Backward traversal
void traverseBackward() {
    struct Node *temp = tail;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// 4. Insertion at beginning
void insertAtBeginning(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

// 5. Insertion at end
void insertAtEnd(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
}

// 6. Deletion at beginning
void deleteAtBeginning() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

// 7. Deletion at end
void deleteAtEnd() {
    if (tail == NULL)
        return;

    struct Node *temp = tail;

    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

// 8. Insertion in the middle
void insertInMiddle(int pos, int value) {
    if (pos < 1)
        return;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

// 9. Deletion from the middle
void deleteFromMiddle(int pos) {
    if (head == NULL || pos < 1)
        return;

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
}

// 10. Searching
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

int main() {
    createThreeNodes();

    printf("Initial Doubly Linked List:\n");
    traverseForward();

    printf("\nBackward Traversal:\n");
    traverseBackward();

    printf("\nInsert 5 at beginning:\n");
    insertAtBeginning(5);
    traverseForward();

    printf("\nInsert 40 at end:\n");
    insertAtEnd(40);
    traverseForward();

    printf("\nInsert 25 at position 3:\n");
    insertInMiddle(3, 25);
    traverseForward();

    printf("\nSearch for 30:\n");
    int result = search(30);

    if (result != -1)
        printf("Element found at position %d\n", result);
    else
        printf("Element not found\n");

    printf("\nDelete at beginning:\n");
    deleteAtBeginning();
    traverseForward();

    printf("\nDelete at end:\n");
    deleteAtEnd();
    traverseForward();

    printf("\nDelete at position 2:\n");
    deleteFromMiddle(2);
    traverseForward();

    return 0;
}
