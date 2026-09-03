#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array containing only 0s, 1s, and 2s
void dutchNationalFlag(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {
            case 0:
                swap(&arr[low], &arr[mid]);
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(&arr[mid], &arr[high]);
                high--;
                break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements (only 0, 1, and 2): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    dutchNationalFlag(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}