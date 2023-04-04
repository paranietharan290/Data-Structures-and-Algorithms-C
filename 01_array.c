#include<stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int arr_size=0;

void InsertAtEnd(int data)
{
    if(arr_size == MAX_SIZE-1)// check array is full or not
    {
        printf("Array is full!\n");
        return;
    }

    arr[arr_size++]=data;

    printf("%d is inserted at end\n",data);
}

void Display()
{
    if(arr_size == 0)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Numbers in list:\n");
    for(int i=0; i<arr_size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

void DeleteAtEnd()
{
    if(arr_size == 0)
    {
        printf("List is empty!\n");
        return;
    }

    int del=arr[arr_size-1];
    arr_size--;
    printf("%d is deleted in last position\n", del);
}

void InsertAtSpecificPosition(int data, int position)
{
    if(arr_size == 0)
    {
        printf("List is empty!\n");
        return;
    }

    for(int i=arr_size-1; i>=position; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[position]=data;
    arr_size++;

    printf("%d is inserted at position %d\n",data,position);
}


void DeleteAtSpecificPosition(int position)
{
    if(position < 0 || position >= arr_size)
    {
        printf("Invalid position!\n");
        return;
    }

    int del=arr[position];

    for(int i=position; i<arr_size-1; i++)
    {
        arr[i]=arr[i+1];
    }

    arr_size--;

    printf("%d is deleted from position %d\n",del,position);
}

int main()
{
    Display();
    printf("\n----\n");

    InsertAtEnd(11);
    InsertAtEnd(25);
    InsertAtEnd(23);
    InsertAtEnd(22);
    InsertAtEnd(16);
    InsertAtEnd(38);

    printf("\n----\n");

    Display();

    printf("\n----\n");

    //DeleteAtEnd();
    InsertAtSpecificPosition(200,2);
    InsertAtSpecificPosition(254,4);

    printf("\n----\n");

    Display();

    DeleteAtSpecificPosition(1);

    printf("\n----\n");
    Display();
    return 0;
}
