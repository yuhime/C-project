#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* linkedList_new() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void linkedList_add(LinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
}

void linkedList_remove(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }

    if (index == 0) {
        Node* old_head = list->head;
        list->head = list->head->next;
        free(old_head);
    } else {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* old_node = current->next;
        current->next = current->next->next;
        free(old_node);
    }

    list->size--;
}

int linkedList_get(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

void linkedList_free(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* oldNode = current;
        current = current->next;
        free(oldNode);
    }
    free(list);
}
