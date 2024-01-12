#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void insertbegin(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void insertend(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void insertrandom(int data, int position)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node ->data = data;
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        struct Node *temp_node = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp_node = temp_node->next;
        }
        new_node->next = temp_node->next;
        temp_node->next = new_node;
    }
}
void traversal(struct Node *start)
{
    struct Node *ptr = start;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    while(1){
        int choice, element, position;
        printf("\n-------------------------------\n\n Linked List Insertion Operations \n\n [1] Insertion in beginning\n [2] Insertion at last\n [3] Insertion at position\n [4] Traversal 'Display\n [5] Exit\n\n Enter your Choice : ");
        scanf("%d", &choice);
        printf("\n-------------------------------\n\n");
        switch (choice)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &element);
            insertbegin(element);
            break;
        case 2:
            printf("Enter Element : ");
            scanf("%d",&element);
            insertend(element);
            break;
        case 3:
            printf("Enter Element : ");
            scanf("%d",&element);
            printf("\nEnter postion : ");
            scanf("%d",&position);
            insertrandom(element, position);
            break;
        case 4:
            traversal(head);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Please ! choice correct option");
            break;
        }
    }
}