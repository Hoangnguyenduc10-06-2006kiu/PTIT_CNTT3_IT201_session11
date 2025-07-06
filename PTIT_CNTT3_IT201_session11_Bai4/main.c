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

int lengthArr(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        head = insertAtTail(head, arr[i]);
    }

    int length = lengthArr(head);
    printf("Danh sach lien ket co %d phan tu\n", length);

    return 0;
}