### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct arrayList {
    int** arr;
    int index;
    int size;
} arrayList;

arrayList* CreateArrayList(int size)
{
    arrayList* l = (arrayList*)malloc(sizeof(arrayList));
    l->size = size;
    l->index = 0;
    l->arr = (int**)malloc(sizeof(int*) * l->size);
    return l;
}

void AddAtIndexArrayList(arrayList* l, int idx, int* k)
{
    memmove(&l->arr[idx + 1], &l->arr[idx], sizeof(int*) * (l->index - idx));
    l->arr[idx] = k;
    l->index++;
    return;
}

int Compare(const void* a, const void* b)
{
    int** pA = (int**)a;
    int** pB = (int**)b;
    if (pA[0][0] == pB[0][0]) {
        return pA[0][1] - pB[0][1];
    } else {
        return pB[0][0] - pA[0][0];
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (!people || peopleSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = peopleSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * peopleSize);
    qsort(people, peopleSize, sizeof(int*), Compare);
    arrayList* l = CreateArrayList(peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
        AddAtIndexArrayList(l, people[i][1], people[i]);
    }
    memcpy(people, l->arr, sizeof(int*) * peopleSize);
    free(l->arr);
    free(l);
    return people;
}
```