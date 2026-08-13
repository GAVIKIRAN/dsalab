#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert a node at the end */
void insert(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted into the list\n", value);
}

/* Display the linked list */
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Delete from beginning */
void deleteFromBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("%d deleted from beginning\n", temp->data);

    free(temp);
}

/* Delete from end */
void deleteFromEnd()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if (head->next == NULL)
    {
        printf("%d deleted from end\n", head->data);

        free(head);
        head = NULL;

        return;
    }

    temp = head;

    /* Go to second-last node */
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    printf("%d deleted from end\n", temp->next->data);

    free(temp->next);
    temp->next = NULL;
}

/* Delete a given element */
void deleteElement(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    /* Search for the element */
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    /* Element not found */
    if (temp == NULL)
    {
        printf("%d not found in the list\n", value);
        return;
    }

    /* If element is the first node */
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    printf("%d deleted from the list\n", value);

    free(temp);
}

int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Delete a Given Element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                deleteFromBeginning();
                break;

            case 4:
                deleteFromEnd();
                break;

            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                deleteElement(value);
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}