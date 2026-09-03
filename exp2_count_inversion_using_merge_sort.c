#include <stdio.h>

int merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0, count = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            count += m - i + 1;
        }
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = temp[k++];

    return count;
}

int mergeSort(int a[], int l, int r)
{
    if (l >= r) return 0;

    int m = (l + r) / 2;
    return mergeSort(a, l, m)
         + mergeSort(a, m + 1, r)
         + merge(a, l, m, r);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Number of inversions: %d\n", mergeSort(a, 0, n - 1));

    return 0;
}