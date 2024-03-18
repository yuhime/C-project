#include "arraylist_generic.h"


int main() {
    ArrayList *list = arrayList_new();
    Data *data1 = malloc(sizeof(Data));
    data1->type = TYPE_INT;
    data1->value.int_value = 42;
    
    arrayList_push(list, data1);

    void *data = arrayList_get(list, 0, TYPE_INT);
    if (data == NULL) {
        printf("invalid value cast\n");
        return 1;
    }

    int value = *((int *)data);

    printf("%d\n", value);

    arrayList_free(list);
    free(data1);

    return 0;
}
