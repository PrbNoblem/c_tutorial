#ifndef LINKED_LIST
#define LINKED_LIST

struct node
{
    int payload;
    struct node *next;
};


void insert(struct node *n, int payload);

void print(struct node *n);


#endif