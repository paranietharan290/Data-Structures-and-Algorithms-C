#include <stdio.h>

#define MAX_SIZE 100

void insertEnd(int arr[], int *size, int element);
void insertAt(int arr[], int *size, int position, int element);
void deleteAt(int arr[], int *size, int position);
void display(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // insert elements at the end
    insertEnd(arr, &size, 10);
    insertEnd(arr, &size, 20);
    insertEnd(arr, &size, 30);
    insertEnd(arr, &size, 40);

    printf("Elements after insertions:\n");
    display(arr, size);

    // insert an element at specific position
    insertAt(arr, &size, 2, 50);
    printf("\nElements after inserting 50 at position 2:\n");
    display(arr, size);

    // delete an element from specific position
    deleteAt(arr, &size, 1);
    printf("\nElements after deleting element at position 1:\n");
    display(arr, size);

    return 0;
}

void insertEnd(int arr[], int *size, int element) {
    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    arr[*size] = element;
    (*size)++;
}

void insertAt(int arr[], int *size, int position, int element) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    for (int i = *size - 1; i >= position; i--) {
        arr[i+1] = arr[i];
    }

    arr[position] = element;
    (*size)++;
}

void deleteAt(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }

    (*size)--;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
