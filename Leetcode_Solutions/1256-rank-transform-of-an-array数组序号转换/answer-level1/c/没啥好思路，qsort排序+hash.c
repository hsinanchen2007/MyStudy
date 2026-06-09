### 解题思路
1. qsort排个序
2. 遍历排序后的数组，加入hash，数字是key，保存排序后的索引（相同的数字 hash中已存在，索引自然为第一个）
3. 遍历原始数组，去hash中查找，得到索引值，输出

### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

struct hash_entry {
    int number; /*key*/
    int seq;
    UT_hash_handle hh;
};



int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    struct hash_entry *htable = NULL;
    int *retArr;
    int i;
    int seq = 1;
    int current;
    struct hash_entry *ele = NULL;

    if (arr == NULL) {
        *returnSize = 0;
        return NULL;
    }

    retArr = (int*)malloc(sizeof(int) * arrSize);
    if (retArr == NULL) {
        *returnSize = 0;
        return NULL;
    }
    (void)memcpy(retArr, arr, sizeof(int) * arrSize);

    qsort(retArr, arrSize, sizeof(int), cmpfunc);

    for (i=0; i<arrSize; i++) {
        current = retArr[i];
        HASH_FIND_INT(htable, &current, ele);
        if (!ele) {
            ele = (struct hash_entry*)malloc(sizeof(struct hash_entry));
            if (ele == NULL) {
                printf("bug: nomem\n");
                return NULL;
            }
            ele->number = current;
            ele->seq = seq;
            seq++;
            HASH_ADD_INT(htable, number, ele);
        }
    }

    for (i=0; i<arrSize; i++) {
        current = arr[i];
        HASH_FIND_INT(htable, &current, ele);
        if (ele == NULL) {
            printf("bug: %d\n", current);
            return NULL;
        }
        retArr[i] = ele->seq;
    }

    *returnSize = arrSize;
    return retArr;
}
```