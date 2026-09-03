#include <stdio.h>

int search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        // Right half is sorted
        else {
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter rotated sorted array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target element: ");
    scanf("%d", &target);

    int result = search(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
