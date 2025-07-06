#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data)
{
    //cap phat bo nho cho node
    Node* newNode = (Node*)malloc(sizeof(Node));
    //gan gia tri
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    //lie ket cac not
    return newNode;
}
Node* printflistlinked(Node* head)
{
    Node* temp = head;
    printf("danh sach lien ket doi la:\n");
    while (temp != NULL)
    {
        printf("%d<=>", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main(void)
{
    Node* head =NULL;

    Node* node1=createNode(10);
    Node* node2=createNode(20);
    Node* node3=createNode(30);
    Node* node4=createNode(40);
    Node* node5=createNode(50);
    // lien ket cac nut
    node1->next=node2;

    node2->prev=node1;
    node2->next=node3;

    node3->prev=node2;
    node3->next=node4;

    node4->next=node5;
    node4->prev=node3;

    node5->prev=node4;

    head =node1;

    printflistlinked(head);
    return 0;
}