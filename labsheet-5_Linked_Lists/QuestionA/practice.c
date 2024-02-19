#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void createLinkedList(int val, struct node **head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void AddtoLinkedList(int val, struct node *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    pointer->data += val;
    if (pointer->data > 9)
    {
        pointer->data %= 10;
        if (pointer->next == NULL)
        {
            createLinkedList(1, &pointer->next);
        }
        else
        {
            pointer->next->data++;
        }
    }
    return;
}
void display(struct node **head)
{
    struct node *ptr = *head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    // taking input
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // creating the linked list
    struct node *head = NULL;
    int small = n <= m ? n : m;
    int big = n > m ? n : m;
    int *smallArr = n <= m ? arr1 : arr2;
    int *bigArr = n > m ? arr1 : arr2;
    for (int i = 0; i < big; i++)
    {
        createLinkedList(bigArr[i], &head);
    }
    // now we have the linked list so we add
    struct node *ptr = head;
    for (int i = 0; i < n + m && ptr != NULL; i++)
    {
        if (i < small)
        {
            AddtoLinkedList(smallArr[i], ptr);
        }
        ptr = ptr->next;
    }
    display(&head);
}