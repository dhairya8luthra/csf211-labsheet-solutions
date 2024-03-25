#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct Queue
{
    struct node *front;
    struct node *rear;
    int max;
};

void print_q(struct Queue *queue)
{
    struct node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *temp = queue->front;
    int val = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    if (val == queue->max)
    {
        queue->max = -1;
        struct node *curr = queue->front;
        while (curr != NULL)
        {
            if (curr->data > queue->max)
            {
                queue->max = curr->data;
            }
            curr = curr->next;
        }
    }

    free(temp);
    return val;
}

void enqueue(struct Queue *queue, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    if (val > queue->max)
    {
        queue->max = val;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->max = -1;

    int head_pointer = 0;
    int tail_pointer = 0;

    // Setting up the initial window
    for (int i = 0; i < k; i++)
    {
        enqueue(queue, arr[i]);
    }
    tail_pointer = k;

    printf("%d head_pointer is at %d\n", queue->max, arr[0]);

    while (tail_pointer < n)
    {
        int element = dequeue(queue);
        enqueue(queue, arr[tail_pointer]);
        tail_pointer++;
        printf("%d head_pointer is at %d\n", queue->max, arr[head_pointer]);
        head_pointer++;
    }

    free(queue);
    return 0;
}