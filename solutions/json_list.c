#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_list.h"

JObject* parse_json(const char *filename) {
    json_error_t err;
    json_t *root = json_load_file(filename, 0, &err);

    if (!root || !json_is_array(root)) {
        fprintf(stderr, "Invalid JSON array\n");
        return NULL;
    }

    JObject *head = NULL;

    size_t index;
    json_t *elem;

    json_array_foreach(root, index, elem) {
        json_t *name = json_object_get(elem, "name");
        json_t *age  = json_object_get(elem, "age");

        if (!json_is_string(name) || !json_is_integer(age))
            continue;

        JObject *n = malloc(sizeof(JObject));
        n->name = strdup(json_string_value(name));
        n->age  = json_integer_value(age);

        n->next = head;
        head = n;
    }

    json_decref(root);
    return head;
}

void print_list(JObject *head) {
    for (JObject *p = head; p; p = p->next)
        printf("%s (%d)\n", p->name, p->age);
}

void free_list(JObject *head) {
    while (head) {
        JObject *next = head->next;
        free(head->name);
        free(head);
        head = next;
    }
}

