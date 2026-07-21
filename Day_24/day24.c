// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    int n, m;
    scanf("%d", &n);
    struct Node *head1 = NULL, *temp1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head1 == NULL)
        {
            head1 = newNode;
            temp1 = head1;
        }
        else
        {
            temp1->next = newNode;
            temp1 = temp1->next;
        }
    }
    scanf("%d", &m);
    struct Node *head2 = NULL, *temp2 = NULL;
    for (int i = 0; i < m; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head2 == NULL)
        {
            head2 = newNode;
            temp2 = head2;
        }
        else
        {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
    }
    struct Node *result = NULL, *temp3 = NULL;
    struct Node *p1 = head1, *p2 = head2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            if (result == NULL)
            {
                result = p1;
                temp3 = result;
            }
            else
            {
                temp3->next = p1;
                temp3 = temp3->next;
            }
            p1 = p1->next;
        }
        else
        {
            if (result == NULL)
            {
                result = p2;
                temp3 = result;
            }
            else
            {
                temp3->next = p2;
                temp3 = temp3->next;
            }
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        if (result == NULL)
        {
            result = p1;
            temp3 = result;
        }
        else
        {
            temp3->next = p1;
            temp3 = temp3->next;
        }
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        if (result == NULL)
        {
            result = p2;
            temp3 = result;
        }
        else
        {
            temp3->next = p2;
            temp3 = temp3->next;
        }
        p2 = p2->next;
    }
    temp3->next = NULL;
    temp3 = result;
    while (temp3 != NULL)
    {
        printf("%d ", temp3->data);
        temp3 = temp3->next;
    }
    return 0;
}