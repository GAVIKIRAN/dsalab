#include <stdio.h>

/* Bubble Sort - Ascending Order */
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Bubble Sort (Ascending): ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* Selection Sort - Descending Order */
void selectionSort(int arr[], int n)
{
    int i, j, max, temp;

    for (i = 0; i < n - 1; i++)
    {
        max = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }

    printf("Selection Sort (Descending): ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[100];
    int n, choice;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n--- Sorting Menu ---\n");
    printf("1. Bubble Sort (Ascending)\n");
    printf("2. Selection Sort (Descending)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            bubbleSort(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}