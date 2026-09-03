#include <stdio.h>

int majorityElement(int arr[], int n) {
    int candidate = 0;
    int count = 0;

    // Moore's Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Verify candidate
    count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;

    return -1;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = majorityElement(arr, n);

    if (result != -1)
        printf("Majority Element: %d\n", result);
    else
        printf("No Majority Element\n");

    return 0;
}
