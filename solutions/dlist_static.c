#include <stdio.h>
#include "dlist.h"

// Static nodes for values 1–5
DNode nodes[5];
DList list;

int main(void) {
    // Initialize static nodes
    for (int i = 0; i < 5; i++) {
        nodes[i].data = (void*)(long)(i + 1);
        nodes[i].prev = (i > 0) ? &nodes[i - 1] : NULL;
        nodes[i].next = (i < 4) ? &nodes[i + 1] : NULL;
    }

    list.head = &nodes[0];
    list.tail = &nodes[4];

    // Forward traversal
    printf("Forward: ");
    for (DNode *p = list.head; p != NULL; p = p->next) {
        printf("%ld ", (long)p->data);
    }
    printf("\n");

    // Backward traversal
    printf("Backward: ");
    for (DNode *p = list.tail; p != NULL; p = p->prev) {
        printf("%ld ", (long)p->data);
    }
    printf("\n");

    return 0;
}
