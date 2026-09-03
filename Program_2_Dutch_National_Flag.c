#include <stdio.h>

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    int temp;

    while (mid <= high) {
        if (arr[mid] == 0) {
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements (only 0, 1 and 2): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort012(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
