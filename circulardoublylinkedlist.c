#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertBeg(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        struct Node *temp = *head_ref;
        struct Node *last = temp->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = temp;
        temp->prev = new_node;
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

        struct Node *ptr = *head_ref;
        do
        {
            if (ptr->data == elem)
            {
                new_node->next = ptr->next;
                new_node->prev = ptr;
                ptr->next->prev = new_node;
                ptr->next = new_node;
                return;
            }
            ptr = ptr->next;
        } while (ptr != *head_ref);
        printf("\nElement not in list\n");
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
        struct Node *ptr = *head_ref;
        int count = 0;
        while (count < pos - 1)
        {
            ptr = ptr->next;
            count++;
            if (ptr == *head_ref)
            {
                printf("\nInvalid position!\n");
                return;
            }
        }
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = ptr->next;
        new_node->prev = ptr;
        if (ptr->next != NULL)
        {
            ptr->next->prev = new_node;
        }
        ptr->next = new_node;
    }
}

void insertEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else
    {
        struct Node *temp = *head_ref;
        struct Node *last = temp->prev;

        new_node->next = *head_ref;
        new_node->prev = last;
        last->next = new_node;
        temp->prev = new_node;
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
        if (temp->next == *head_ref)
        {
            *head_ref = NULL;
            free(temp);
            return;
        }
        struct Node *nex = temp->next;
        struct Node *last = temp->prev;
        nex->prev = last;
        last->next = nex;
        free(temp);
        *head_ref = nex;
    }
}

void deleteElem(struct Node **head_ref, int elem)
{
    struct Node *ptr = *head_ref;
    if (*head_ref == NULL)
    {
        printf("\nEmpty list\n");
    }
    else if (ptr->data == elem)
    {
        deleteBeg(head_ref);
    }
    else
    {
        do
        {
            if (ptr->data == elem)
            {
                struct Node *pre = ptr->prev;
                struct Node *nex = ptr->next;
                pre->next = nex;
                nex->prev = pre;
                return;
            }
            ptr = ptr->next;
        } while (ptr != *head_ref);
        printf("\nNot in list\n");
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
        deleteBeg(head_ref);
    }
    else
    {
        struct Node *curr = *head_ref;
        int i;
        for (i = 0; i < pos && curr->next != *head_ref; i++)
        {
            curr = curr->next;
        }
        if (curr->next == *head_ref && i != pos)
        {
            printf("\nInvalid position\n");
        }
        else
        {
            struct Node *nex = curr->next;
            struct Node *pre = curr->prev;
            nex->prev = pre;
            pre->next = nex;
            free(curr);
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
        struct Node *curr = *head_ref;
        if (curr->next == *head_ref)
        {
            *head_ref = NULL;
            free(curr);
            return;
        }
        struct Node *temp = curr->prev;
        struct Node *prev = temp->prev;
        curr->prev = prev;
        prev->next = curr;
        free(temp);
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
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}

void printListRev(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        printf("\nElements in list: ");
        struct Node *ptr = head;
        do
        {
            ptr = ptr->prev;
            printf("%d ", ptr->data);
        } while (ptr != head);
        printf("\n");
    }
}

int main()
{
    struct Node *head = NULL;
    int ch = 0;
    while (ch != 11)
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
        printf("10. Display list in reverse\n");
        printf("11. Exit\n");
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
            printListRev(head);
            break;
        case 11:
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
