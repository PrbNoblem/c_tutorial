#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


void insert(struct node *n, int payload)
{
    struct node *c_node = n;

    int len = 0;
    while(c_node->next != NULL)
    {
        c_node = c_node->next;
        //printf("Len of list: %d\n", len++);
    }
    struct node *n_node = malloc(sizeof(struct node));
    n_node->payload = payload;
    n_node->next = NULL;
    c_node->next = n_node;
}

void print(struct node *n)  
{
    int count = 0;
    do
    {
        printf("Node: %d has payload: %d\n", count++, n->payload);
        n = n->next;
    } while (n != NULL);
}