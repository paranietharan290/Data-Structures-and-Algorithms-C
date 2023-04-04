#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow!\n");
        return;
    }
    printf("Removed element: %d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);

    display();
    return 0;
}
