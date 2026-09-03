#include <stdio.h>

double findMedian(int A[], int n, int B[], int m) {
    if (n > m)
        return findMedian(B, m, A, n);

    int low = 0, high = n;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n + m + 1) / 2 - i;

        int leftA  = (i == 0) ? -9999 : A[i - 1];
        int rightA = (i == n) ? 9999 : A[i];

        int leftB  = (j == 0) ? -9999 : B[j - 1];
        int rightB = (j == m) ? 9999 : B[j];

        if (leftA <= rightB && leftB <= rightA) {
            if ((n + m) % 2 == 0)
                return (double)(leftA > leftB ? leftA : leftB)
                     + (double)(rightA < rightB ? rightA : rightB) / 2.0;
            else
                return (leftA > leftB ? leftA : leftB);
        }
        else if (leftA > rightB)
            high = i - 1;
        else
            low = i + 1;
    }

    return 0;
}

int main() {
    int A[] = {1, 3};
    int B[] = {2};

    printf("Median = %.1f\n", findMedian(A, 2, B, 1));

    return 0;
}