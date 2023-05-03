#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll
{
    int data;
    struct single_ll *next;
}sll;

void insert_at_last(int data_arg, sll **head_arg);
void reverse_list(sll **head_arg);
int count_node(sll **head_arg);
void delete_alt_node(sll **head_arg);
void display(sll **head_arg);

int main()
{
    sll *head = NULL;
    int data, option;
    while(1)
    {
        printf("1. Insert at last\n2. Reverse list\n3. Count node\n4. Delete alternate node\n5. Display\n6. Exit\nEnter the option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter data: ");
                    scanf("%d", &data);
                    insert_at_last(data, &head);
                    break;
            case 2: reverse_list(&head);
                    break;
            case 3: int len = count_node(&head);
                    printf("Length is %d\n",len);
                    break;
            case 4: delete_alt_node(&head);
                    break;
            case 5: display(&head);
                    break;
            case 6: exit(1);
                    break;
        }
    }
    return 0;
}

void insert_at_last(int data_arg, sll **head_arg)
{
    sll *node = (sll *)malloc(sizeof(sll));
    if(node == NULL)
    {
        printf("Memory not assigned\n");
    }
    else
    {
        node->data = data_arg;
        node->next = NULL;
        if(*head_arg == NULL)
        {
            *head_arg = node;
        }
        else
        {
            sll *temp = *head_arg;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
}

void reverse_list(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        sll *prev = NULL;
        sll *next = NULL;
        while(temp != NULL)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        *head_arg = prev;
    }
    
}

int count_node(sll **head_arg)
{
    int count = 0;
    sll *temp = *head_arg;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void delete_alt_node(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *prev,*next_node;
        prev = *head_arg;
        while(prev->next != NULL)
        {
            next_node = prev->next;
            prev->next = next_node->next;
            free(next_node);
            prev = prev->next;
        }
    }
}

void display(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        printf("Elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}