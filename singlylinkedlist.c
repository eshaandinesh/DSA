#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertBeg(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *head_ref;
    }
    *head_ref = new_node;
}

void insertMid(struct Node **head_ref, int new_data, int elem)
{
    if (*head_ref == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = new_data;
        struct Node *temp = *head_ref;
        while (temp->data != elem && temp != NULL)
        {
            temp = temp->next;
        }
        if (temp->data == elem)
        {
            new_node->next = temp->next;
            temp->next = new_node;
        }
        else
        {
            printf("\nNot in list\n");
        }
    }
}

void insertPos(struct Node **head_ref, int pos, int new_data)
{
    if (pos < 0)
    {
        printf("\nInvalid position!\n");
    }
    else if (pos == 0)
    {
        insertBeg(head_ref, new_data);
    }
    else
    {
        struct Node *prev = *head_ref;
        int count = 0;
        while (count < pos - 1 && prev != NULL)
        {
            prev = prev->next;
            count++;
        }
        if (prev == NULL)
        {
            printf("\nInvalid position!\n");
        }
        else
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = new_data;
            temp->next = prev->next;
            prev->next = temp;
        }
    }
}

void insertEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
    {
        struct Node *temp = *head_ref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteBeg(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        struct Node *temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
}

void deleteElem(struct Node **head_ref, int elem)
{
    if (*head_ref == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        struct Node *prevptr = NULL;
        struct Node *ptr = *head_ref;
        if (ptr->data == elem && prevptr == NULL)
        {
            *head_ref = ptr->next;
            free(ptr);
        }
        else
        {
            while (ptr != NULL && ptr->data != elem)
            {
                prevptr = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                printf("\nNot in list\n");
                return;
            }
            prevptr->next = ptr->next;
            free(ptr);
        }
    }
}

void deletePos(struct Node **head_ref, int pos)
{
    if (*head_ref == NULL)
    {
        printf("\nEmpty list\n");
    }
    else if (pos < 0)
    {
        printf("\nInvalid position\n");
    }
    else if (pos == 0)
    {
        struct Node *temp = *head_ref;
        struct Node *ptr = *head_ref;
        ptr = ptr->next;
        *head_ref = ptr;
        free(temp);
    }
    else
    {
        struct Node *curr = *head_ref;
        for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
        {
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            printf("\nInvalid position\n");
        }
        else
        {
            struct Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
    }
}

void deleteEnd(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        struct Node *prevptr = NULL;
        struct Node *ptr = *head_ref;
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        if (prevptr == NULL)
        {
            free(ptr);
            *head_ref = NULL;
            return;
        }
        else
        {
            prevptr->next = NULL;
            free(ptr);
        }
    }
}

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        printf("\nElements in list: ");
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Node *head = NULL;
    int ch = 0;
    while (ch != 10)
    {
        printf("\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert after Element\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Delete Element\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        int elem;
        int pos;
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            int elem;
            scanf("%d", &elem);
            insertBeg(&head, elem);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &elem);
            insertEnd(&head, elem);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter element: ");
            scanf("%d", &elem);
            insertPos(&head, pos, elem);
            break;
        case 4:
            printf("Enter element: ");
            scanf("%d", &elem);
            printf("Enter element after which it must be inserted: ");
            int currelem;
            scanf("%d", &currelem);
            insertMid(&head, elem, currelem);
            break;
        case 5:
            deleteBeg(&head);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(&head, pos);
            break;
        case 8:
            printf("Enter element: ");
            scanf("%d", &elem);
            deleteElem(&head, elem);
            break;
        case 9:
            printList(head);
            break;
        case 10:
            return 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
