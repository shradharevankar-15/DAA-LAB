#include <stdio.h>

double findMedian(int A[], int n, int B[], int m) {
    // Make A the smaller array
    if (n > m)
        return findMedian(B, m, A, n);

    int low = 0;
    int high = n;

    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = (n + m + 1) / 2 - partitionA;

        int maxLeftA = (partitionA == 0) ? -1000000 : A[partitionA - 1];
        int minRightA = (partitionA == n) ? 1000000 : A[partitionA];

        int maxLeftB = (partitionB == 0) ? -1000000 : B[partitionB - 1];
        int minRightB = (partitionB == m) ? 1000000 : B[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((n + m) % 2 == 0) {
                int leftMax = (maxLeftA > maxLeftB) ? maxLeftA : maxLeftB;
                int rightMin = (minRightA < minRightB) ? minRightA : minRightB;

                return (leftMax + rightMin) / 2.0;
            }
            else {
                return (maxLeftA > maxLeftB) ? maxLeftA : maxLeftB;
            }
        }
        else if (maxLeftA > minRightB) {
            high = partitionA - 1;
        }
        else {
            low = partitionA + 1;
        }
    }

    return -1;
}

int main() {
    int n, m;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter first sorted array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter size of second sorted array: ");
    scanf("%d", &m);

    int B[m];

    printf("Enter second sorted array: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]);

    double median = findMedian(A, n, B, m);

    printf("Median: %.2f\n", median);

    return 0;
}
