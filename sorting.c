#include<stdio.h>

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    int temp, j;
    for(int i=1; i<size; i++)
    {
        temp=arr[i];

        j=i-1;

        while(arr[j]>temp && j>=0)//loop elements that greater than temp
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;//store temp in correct position
    }
}

void selectionSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        int minIndex=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
        }

        // swapping numbers
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("Array before sorting: ");
  printArray(arr, n);

  bubbleSort(arr, n);
  printf("Array after Bubble sort: ");
  printArray(arr, n);

  int arr1[] = {64, 25, 12, 22, 11};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);

  insertionSort(arr1, n1);
  printf("Array after Insertion sort: ");
  printArray(arr1, n1);

  int arr2[] = {64, 25, 12, 22, 11};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);

  selectionSort(arr2, n2);
  printf("Array after Selection sort: ");
  printArray(arr2, n2);

  return 0;
}
