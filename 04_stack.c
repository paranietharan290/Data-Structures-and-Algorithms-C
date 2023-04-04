#include<stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if(top == MAX_SIZE-1)
    {
        printf("stack overflow!\n");
        return;
    }

    stack[++top]=data;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }

    return stack[top--];
}

int peek()
{
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Peek: %d\n", peek());

    printf("Pop: %d\n", pop());

    printf("Peek: %d\n", peek());

    push(40);
    printf("Peek: %d\n", peek());
    printf("Pop: %d\n", pop());
    printf("Peek: %d\n", peek());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Peek: %d\n", peek());
    return 0;
}
