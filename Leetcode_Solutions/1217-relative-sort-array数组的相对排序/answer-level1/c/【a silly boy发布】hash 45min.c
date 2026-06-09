```
struct HashNode {
    int key;
    int cnt;
    UT_hash_handle hh;
};
struct HashNode *g_this = NULL;

struct HashNodeNEXT {
    int key;
    int cnt;
    UT_hash_handle hh;
};
struct HashNodeNEXT *g_this_next = NULL;

int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void ClearHashNode1() 
{
    struct HashNode *current;
    struct HashNode *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }
}

void ClearHashNode2() 
{
    struct HashNodeNEXT *current;
    struct HashNodeNEXT *tmp;
    HASH_ITER(hh, g_this_next, current, tmp) {
        HASH_DEL(g_this_next, current);
        free(current);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *returnArray = (int *)malloc(arr1Size * sizeof(int));
    memset(returnArray, 0, arr1Size * sizeof(int));

    int i;
    int key;
    struct HashNode *tmp2HashNode;
    for (i = 0; i < arr2Size; i++) {
        key = arr2[i];
        HASH_FIND_INT(g_this, &key, tmp2HashNode);
        if (tmp2HashNode == NULL) {
            tmp2HashNode = (struct HashNode *)malloc(sizeof(struct HashNode));
            tmp2HashNode->key = key;
            tmp2HashNode->cnt = 0;
            tmp2HashNode->cnt++;
            HASH_ADD_INT(g_this, key, tmp2HashNode);
        } else {
            tmp2HashNode->cnt++;
        }
    }
    
    struct HashNode *tmpArr1HashNode;
    int tmpArray[arr1Size];
    int tmpArrayIndex = 0;

    struct HashNodeNEXT *tmpHashNodeNEXT;
    for (i = 0; i < arr1Size; i++) {
        key = arr1[i];
        HASH_FIND_INT(g_this, &key, tmpArr1HashNode);
        if (tmpArr1HashNode == NULL) {
            tmpArray[tmpArrayIndex] = arr1[i];
            tmpArrayIndex++;
        } else {
            HASH_FIND_INT(g_this_next, &key, tmpHashNodeNEXT);
            if (tmpHashNodeNEXT == NULL) {
                tmpHashNodeNEXT = (struct HashNodeNEXT *)malloc(sizeof(struct HashNodeNEXT));
                tmpHashNodeNEXT->key = key;
                tmpHashNodeNEXT->cnt = 0;
                tmpHashNodeNEXT->cnt++;
                HASH_ADD_INT(g_this_next, key, tmpHashNodeNEXT);
            } else {
                tmpHashNodeNEXT->cnt++;
            }
        }
    }

    qsort(tmpArray, tmpArrayIndex, sizeof(tmpArray[0]), Cmp);

    int returnArrayIndex = 0;

    struct HashNodeNEXT *tmpHashNodeNEXT2;
    int j;
    for (i = 0; i < arr2Size; i++) {
        key = arr2[i];
        HASH_FIND_INT(g_this_next, &key, tmpHashNodeNEXT2);
        if (tmpHashNodeNEXT2 != NULL) {
            for (j = 0; j < tmpHashNodeNEXT2->cnt; j++) {
                returnArray[returnArrayIndex] = tmpHashNodeNEXT2->key;
                returnArrayIndex++;
            }
        }
    }
    for (i = 0; i < tmpArrayIndex; i++) {
        returnArray[returnArrayIndex] = tmpArray[i];
        returnArrayIndex++;
    }

    ClearHashNode1();
    ClearHashNode2();
    *returnSize = arr1Size;
    return returnArray;
}
```
