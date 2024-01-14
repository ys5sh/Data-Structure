#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertFirst(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // circular linked list
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
}

void insertLast(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head; // Fix: Update the last node's next pointer
        temp->next = newNode;
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty !");
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
    }
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is Empty !");
    }
    else
    {
        struct Node *p1 = head->next, *p2 = p1->next;
        while (p2->next != head)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = head;
        free(p2);
    }
}

void traversal(struct Node *start)
{
    struct Node *ptr = start;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}

int main()
{
    int choice, element;
    while (1)
    {
        printf("\n--------------------------------------------\n\n Circular Linked List \n\n [1] Insert in beginning\n [2] Insert at Last\n [3] Delete in beginning\n [4] Delete at last\n [5] Traversal\n [6] Exit \n\n Enter your Choice : ");
        scanf("%d", &choice);
        printf("\n\n--------------------------------------------\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &element);
            insertFirst(element);
            break;
        case 2:
            printf("Enter Element : ");
            scanf("%d", &element);
            insertLast(element);
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            traversal(head);
            break;
        case 6:
            return 0;
            break;
        default:
            printf("Please! Enter correct choice");
            break;
        }
    }
    return 0;
}
