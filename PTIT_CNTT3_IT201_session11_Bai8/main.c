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
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

// thêm node
Node* position(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 || temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Vi tri khong hop le\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 5; i++)
        head = insertAtTail(head, i);
    printf("Danh sach ban dau:");
    printList(head);
    int value, pos;
    printf("Nhap gia tri can them:");
    scanf("%d", &value);
    printf("Nhap vi tri muon them:");
    scanf("%d", &pos);
    head = position(head, value, pos);
    printf("Danh sach sau khi them:");
    printList(head);

    return 0;
}