#include <stdio.h>

int isPossible(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (currentPages + books[i] <= maxPages) {
            currentPages += books[i];
        }
        else {
            studentCount++;
            currentPages = books[i];

            if (studentCount > students)
                return 0;
        }
    }

    return 1;
}

int allocatePages(int books[], int n, int students) {
    if (students > n)
        return -1;

    int low = 0;
    int high = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > low)
            low = books[i];

        high += books[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, students, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, students;

    printf("Enter number of books: ");
    scanf("%d", &n);

    int books[n];

    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &books[i]);

    printf("Enter number of students: ");
    scanf("%d", &students);

    int result = allocatePages(books, n, students);

    if (result == -1)
        printf("Allocation not possible\n");
    else
        printf("Minimum possible maximum pages: %d\n", result);

    return 0;
}
