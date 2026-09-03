#include <iostream>
using namespace std;

// Function for Iterative Insertion Sort
void iterativeInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function for Recursive Insertion Sort
void recursiveInsertionSort(int arr[], int n)
{
    if (n <= 1)
        return;

    // Sort first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert last element into sorted array
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i]; // Copy for recursive sort
    }

    iterativeInsertionSort(arr1, n);
    cout << "\nSorted Array using Iterative Insertion Sort:\n";
    printArray(arr1, n);

    recursiveInsertionSort(arr2, n);
    cout << "\nSorted Array using Recursive Insertion Sort:\n";
    printArray(arr2, n);

    return 0;
}