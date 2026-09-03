#include <stdio.h>

int isPossible(int books[], int n, int students, int maxPages) {
    int count = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + books[i] > maxPages) {
            count++;
            pages = books[i];

            if (count > students)
                return 0;
        } else {
            pages += books[i];
        }
    }
    return 1;
}

int allocatePages(int books[], int n, int students) {
    int low = 0, high = 0, mid, ans;

    for (int i = 0; i < n; i++) {
        if (books[i] > low)
            low = books[i];
        high += books[i];
    }

    while (low <= high) {
        mid = (low + high) / 2;

        if (isPossible(books, n, students, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int books[] = {12, 34, 67, 90};
    int n = 4, students = 2;

    printf("Minimum maximum pages = %d\n",
           allocatePages(books, n, students));

    return 0;
}