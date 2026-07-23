#include <stdlib.h>
#include "slist.h"

SNode* add_node(SNode *head, int value) {
    SNode *n = malloc(sizeof(SNode));
    n->value = value;
    n->next = head;
    return n;
}

int count_nodes(SNode *head) {
    int count = 0;
    for (SNode *p = head; p; p = p->next)
        count++;
    return count;
}

void free_list(SNode *head) {
    SNode *p = head;
    while (p) {
        SNode *next = p->next;
        free(p);
        p = next;
    }
}
