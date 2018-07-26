#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct node *root_node = malloc(sizeof(struct node));    
    root_node->payload = 0;
    root_node->next = NULL;
    
    for(int i = 0; i < 10; i++)
    {
        insert(root_node, i*2);
        printf("%d inserted!\n", i*2);
    }
    
    print(root_node);
    
    
    
    
    
    return 0;
}