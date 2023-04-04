#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

typedef struct Node Node;

void InsertAtBeginning(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at the beginning of the list.\n", value);
}

void InsertAtPosition(int data, int position)
{
    // if position less than one, it is invalid positon
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    //if position equals to 0, then call InsertAtBeginning() function
    if (position == 0)
    {
        InsertAtBeginning(data);
        return;
    }

    Node* temp=head;

    for(int i=1; i<position; i++)
    {
        temp=temp->next;
        if(temp == NULL)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;

    newNode->next=temp->next;
    temp->next=newNode;

    printf("%d is inserted at posion-%d\n",data,position);
}

void InsertAtEnd(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    if(head == NULL)
    {
        head=newNode;
        printf("%d inserted at the end of the list.\n", data);
        return;
    }

    Node* temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at the end of the list.\n", data);
}

void DisplayList()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("\nElements in List : \n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void DeleteAtPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if(position==0)
    {
        Node* nodeToDelete = head;
        head = nodeToDelete->next;
        free(nodeToDelete);
        printf("Node at position %d is deleted from the list.\n", position);
        return;
    }

    Node* currentNode=head;
    Node* previousNode = NULL;
    for(int i=0; i<position; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;

        if (currentNode == NULL)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    previousNode->next = currentNode->next;
    free(currentNode);

    printf("Node at position %d is deleted from the list.\n", position);
}


Node* remove_duplicates(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* current = head;
    Node* previous = NULL;
    while (current != NULL)
    {
        Node* runner = head;
        while (runner != current)
        {
            if (runner->data == current->data)
            {
                // Remove the duplicate node
                previous->next = current->next;
                free(current);
                current = previous->next;
                break;
            }
            runner = runner->next;
        }
        if (runner == current)
        {
            previous = current;
            current = current->next;
        }
    }
    return head;
}

Node* insert_at_middle(Node* head, int value)
{
    if (head == NULL)
    {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    int middle = (count + 1) / 2;
    int position = 1;
    current = head;
    while (position < middle)
    {
        current = current->next;
        position++;
    }
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

int main()
{
    InsertAtBeginning(11);
    InsertAtBeginning(25);
    InsertAtBeginning(23);
    InsertAtBeginning(22);
    InsertAtBeginning(16);
    InsertAtBeginning(11);

    DisplayList();

    InsertAtPosition(200,2);

    InsertAtEnd(2908);
    DisplayList();

    DeleteAtPosition(2);

    head = remove_duplicates(head);
    DisplayList();
    return 0;
}
