#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int len;
    int capacity;
} ArrayList;

ArrayList* arrayList_new() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = NULL;
    list->len = 0;
    list->capacity = 0;
    return list;
}

void arrayList_push(ArrayList* list, int value) {
    if (list->len == list->capacity) {
        int new_capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        int* new_data = (int*)realloc(list->data, new_capacity * sizeof(int));
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->len] = value;
    list->len++;
}


int arrayList_pop(ArrayList* list) {
    if (list->len == 0) {
        return -1;
    }
    list->len--;
    int value = list->data[list->len];
    list->data[list->len] = 0;
    return value;
}

int arrayList_is_empty(ArrayList* list) {
    return list->len == 0;
}

int arrayList_len(ArrayList* list) {
    return list->len;
}

int arrayList_get(ArrayList* list, int index) {
    if (index >= list->len) {
        return -1;
    }
    return list->data[index];
}

void arrayList_insert(ArrayList* list, int index, int value) {
    if (list->len == list->capacity) {
        int new_capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->data = (int*)realloc(list->data, new_capacity * sizeof(int));
        list->capacity = new_capacity;
    }
    for (int i = list->len - 1; i >= index; i--) {
        list->data[i+1] = list->data[i];
    }
    list->data[index] = value;
    list->len++;
}

void arrayList_remove(ArrayList* list, int index) {
    if (index >= list->len) {
        return;
    }
    for (int i = index; i < list->len - 1; i++) {
        list->data[i] = list->data[i+1];
    }
    list->len--;
    list->data[list->len] = 0;
}

void arrayList_free(ArrayList* list) {
    free(list->data);
    free(list);
}
