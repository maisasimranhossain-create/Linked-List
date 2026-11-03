
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
    third->next = first;

    head = first;
}

// 2. Traversal
void traversal() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// 3. Insertion at beginning
void insertAtBeginning(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

// 4. Insertion at end
void insertAtEnd(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = head;
}

// 5. Deletion at beginning
void deleteAtBeginning() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    struct Node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}

// 6. Deletion at end
void deleteAtEnd() {
    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head;
    struct Node *prev = NULL;

    while (last->next != head) {
        prev = last;
        last = last->next;
    }

    prev->next = head;
    free(last);
}

// 7. Insertion in the middle
void insertInMiddle(int pos, int value) {
    if (pos < 1)
        return;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    if (head == NULL)
        return;

    struct Node *temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != pos - 1)
        return;

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

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

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos)
        return;

    prev->next = temp->next;
    free(temp);
}

// 9. Searching
int search(int key) {
    if (head == NULL)
        return -1;

    struct Node *temp = head;
    int pos = 1;

    do {
        if (temp->data == key)
            return pos;

        temp = temp->next;
        pos++;

    } while (temp != head);

    return -1;
}

int main() {
    createThreeNodes();

    printf("Initial Circular Linked List:\n");
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

    return 0;
}
