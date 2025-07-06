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
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target)
            return 1;
        temp = temp->next;
    }
    return 0;
}
int main() {
    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        head = insertAtTail(head, arr[i]);
    }
    int number;
    printf("Nhap so can tim: ");
    scanf("%d", &number);
    if (search(head, number))
        printf("True");
    else
        printf("False");

    return 0;
}