#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} 
Node;

void push_front(Node **head, int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = x;
    n->next = *head;
    *head = n;
}

int delete_value(Node **head, int x) {
    if (!*head) return 0;
    if ((*head)->data == x) {
        Node *t = *head;
        *head = (*head)->next;
        free(t);
        return 1;
    }
    Node *p = *head;
    while (p->next && p->next->data != x) p = p->next;
    if (!p->next) return 0;
    Node *t = p->next;
    p->next = t->next;
    free(t);
    return 1;
}

void print_list(const Node *head) {
    const Node *p = head;
    printf("[");
    while (p) {
        printf("%d", p->data);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("]\n");
}

void free_list(Node **head) {
    Node *p = *head;
    while (p) {
        Node *n = p->next;
        free(p);
        p = n;
    }
    *head = NULL;
}

int main(void) {
    Node *head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    push_front(&head, 40);

    printf("List: ");
    print_list(head);

    int x;
    printf("Delete value: ");
    if (scanf("%d", &x) != 1) { free_list(&head); return 1; }

    if (delete_value(&head, x)) {
        printf("After delete: ");
        print_list(head);
    } else {
        printf("Not found. ");
        print_list(head);
    }

    free_list(&head);
    return 0;
}
