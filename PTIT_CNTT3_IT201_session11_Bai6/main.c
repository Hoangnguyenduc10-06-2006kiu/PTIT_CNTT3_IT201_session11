#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertAtTail(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node* head) {
    printf("Danh sach hien tai: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node* deleteFirst(Node* head) {
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);

    return head;
}

int main() {
    Node* head = NULL;
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    printList(head);
    head = deleteFirst(head);
    printf("Sau khi xoa phan tu dau:\n");
    printList(head);

    return 0;
}