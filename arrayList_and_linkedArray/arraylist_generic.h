#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    void **data;
    int len;
    int capacity;
} ArrayList;

typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_BOOL
} DataType;

typedef struct
{
    DataType type;
    union
    {
        int int_value;
        float float_value;
        char char_value;
        bool bool_value;
    } value;
} Data;

ArrayList *arrayList_new()
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = NULL;
    list->len = 0;
    list->capacity = 0;
    return list;
}

void arrayList_push(ArrayList *list, void *value)
{
    if (list->len == list->capacity)
    {
        int new_capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        void **new_data = (void **)realloc(list->data, new_capacity * sizeof(void *));
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->len] = value;
    list->len++;
}

void *arrayList_get(ArrayList *list, int index, DataType type)
{
    if (index < 0 || index >= list->len)
    {
        return NULL;
    }
    Data *data = (Data *)list->data[index];

    if (data->type == type)
    {
        switch (type)
        {
        case TYPE_INT:
            return &(data->value.int_value);

        case TYPE_CHAR:
            return &(data->value.char_value);

        case TYPE_BOOL:
            return &(data->value.bool_value);

        case TYPE_FLOAT:
            return &(data->value.float_value);

        default:
            return NULL;
        }
    }

    return NULL;
}

void arrayList_free(ArrayList *list)
{
    free(list->data);
    free(list);
}