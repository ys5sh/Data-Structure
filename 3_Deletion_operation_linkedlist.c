#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void insert(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
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
void deletefirst()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
}
void deletelast()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *p1 = head, *p2 = p1->next;
    while (p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = NULL;
    free(p2);
}
void deleteposition(int position)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *p1 = head, *p2 = p1->next;
    if (position == 1)
    {
        head = p2;
        free(p1);
        return;
    }
    for (int i = 1; i < position - 1; i++)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p2->next;
    free(p2);
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
    while (1)
    {
        int choice, position, element;
        printf("\n------------------------------------\n\n Deletion Operation in Linked List \n\n [1] Delete in beginning\n [2] Deletion at Last\n [3] Deletion from position\n [4] Insertion\n [5] Traversal\n [6] Exit \n\n > Enter your choice : ");
        scanf("%d", &choice);
        printf("\n--------------------------------\n\n");

        switch (choice)
        {
        case 1:
            deletefirst();
            break;
        case 2:
            deletelast();
            break;
        case 3:
            printf("Enter Position : ");
            scanf("%d", &position);
            deleteposition(position);
            break;
        case 4:
            printf("Enter Element : ");
            scanf("%d", &element);
            insert(element);
            break;
        case 5:
            traversal(head);
            break;
        case 6:
            
            return 0;
            break;
        default:
            printf("Please input the correct choice.\n");
            break;
        }
    }

    return 0;
}
