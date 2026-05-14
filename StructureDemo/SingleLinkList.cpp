#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initList()
{
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void headInsert(Node *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}
void tailInsert(Node *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *head = list;
    node->data = data;
    node->next = NULL;
    list = list->next;
    if (head->next == NULL)
    {
        head->next = node;
        head->data++;
        return;
    }
    while (list->next)
    {
        list = list->next;
    }
    list->next = node;
    head->data++;
}
void Listdelete(Node *list, int data)
{
    Node *pre = list;
    Node *current = list->next;
    while (current->next)
    {
        if (current->data == data)
        {
            pre->next = current->next;
            free(current);
            break;
        }
        pre = pre->next;
        current = current->next;
    }
    list->data--;
}

void printList(Node *list)
{
    list = list->next;
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int searchList(Node *list, int data)
{
}

int main()
{
    Node *list = initList();
    tailInsert(list, 4);
    printList(list);
}