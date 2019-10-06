#include "linkedlist.h"

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/*  */
List *createList()
{

    List *newList = malloc(sizeof(List));

    if (newList == NULL)
        return NULL;

    newList->head = NULL;

    return newList;
}

void insertAtLast(List *l, int data)
{
    if (l->head == NULL)
        l->head = createNode(data);
    else
    {
        Node *temp = l->head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = createNode(data);
    }
}

void insertAtFirst(List *l, int data)
{
    if (l->head == NULL)
        l->head = createNode(data);
    else
    {
        Node *temp = createNode(data);
        temp->next = l->head;
        l->head = temp;
    }
}

void removeLast(List *l)
{
    if(l->head != NULL){
        
        Node* temp = l->head;
        
        while(temp->next->next != NULL)
            temp = temp->next;
        
        free(temp->next);
        temp->next = NULL;


    }
}

void removeFirst(List *l)
{
    if (l->head != NULL)
    {
        Node *temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

void printList(List *l)
{
    Node *temp = l->head;

    if (l->head == NULL)
        return;

    printf("[ ");
    while (temp->next != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    printf("%d ]\n", temp->data);
}