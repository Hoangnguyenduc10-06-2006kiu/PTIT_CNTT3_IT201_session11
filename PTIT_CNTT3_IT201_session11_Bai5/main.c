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

// thêm vào đầu danh sách
Node* insertAtHead(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }

}
int main() {
    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        head = insertAtTail(head, arr[i]);

    printf("Danh sach ban dau:\n");
    printList(head);
    printf("\n");
    int a;
    printf("Nhap so muon them vao dau danh sach:");
    scanf("%d", &a);

    // thêm vào đầu
    head = insertAtHead(head, a);
    printf("Danh sach sau khi them:");
    printList(head);

    return 0;
}