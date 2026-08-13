#include <stdio.h>

/* Linear Search */
int linearSearch(int arr[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

/* Binary Search */
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[100];
    int n, key, choice, result;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\n--- Search Menu ---\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        result = linearSearch(arr, n, key);

        if (result != -1)
            printf("Element found at position %d\n", result + 1);
        else
            printf("Element not found\n");
    }
    else if (choice == 2)
    {
        result = binarySearch(arr, n, key);

        if (result != -1)
            printf("Element found at position %d\n", result + 1);
        else
            printf("Element not found\n");
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}