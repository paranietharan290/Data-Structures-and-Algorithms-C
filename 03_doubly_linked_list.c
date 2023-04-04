#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
};

typedef struct Node Node;

Node* head=NULL;
Node* tail=NULL;

void InsertAtBeginning(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data=data;
    newNode->next=head;

    if(head==NULL){
        tail=newNode;
    }
    else
    {
        head->previous=newNode;
    }

    head=newNode;
    head->previous=NULL;

    printf("%d is inserted at the beginning\n",data);
}

void Display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp=head;
    printf("Elements in list : \n");
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}


void InsertAtSpecificPosition(int pos, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(pos==0)
    {
        InsertAtBeginning(data);
        return;
    }

    newNode->data=data;

    Node* current = head;
    int i = 0;

    while(current!=NULL && i<pos-1)
    {
        current = current->next;
        i++;
    }

    if(current==NULL || current->next==NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->previous = current;
    newNode->next = current->next;
    current->next->previous = newNode;
    current->next = newNode;
}

void DeleteAtSpecificPosition(int pos);

int main()
{
    InsertAtBeginning(10);
    InsertAtBeginning(11);
    InsertAtBeginning(16);
    InsertAtBeginning(20);
    InsertAtBeginning(23);
    InsertAtBeginning(25);
    InsertAtBeginning(92);

    Display();

    InsertAtSpecificPosition(2,298);
    Display();
    return 0;
}
