#include <stdio.h>

// Function to find the majority candidate
int findCandidate(int arr[], int n)
{
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

// Function to verify whether the candidate is actually the majority
int isMajority(int arr[], int n, int candidate)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    return (count > n / 2);
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int candidate = findCandidate(arr, n);

    if (isMajority(arr, n, candidate))
    {
        printf("Majority Element: %d\n", candidate);
    }
    else
    {
        printf("No Majority Element exists.\n");
    }

    return 0;
}