#include <stdio.h>

// Function to search target in rotated sorted array
int searchRotatedArray(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == target)
            return mid;

        // Check if left half is sorted
        if (arr[low] <= arr[mid])
        {
            // Target lies in the sorted left half
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Otherwise, right half is sorted
        else
        {
            // Target lies in the sorted right half
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main()
{
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the rotated sorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target element: ");
    scanf("%d", &target);

    int index = searchRotatedArray(arr, n, target);

    if (index != -1)
        printf("Element found at index: %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}