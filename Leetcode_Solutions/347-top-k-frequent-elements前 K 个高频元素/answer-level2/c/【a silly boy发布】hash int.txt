![800F10FF-FD75-4310-B39B-921FE3BD73C7.jpeg](https://pic.leetcode-cn.com/0e9f68cd26b54d63a1e8654e818762bdf5f58199733229b73096f3075b279222-800F10FF-FD75-4310-B39B-921FE3BD73C7.jpeg)

```
struct HashEntry {
    int key;
    int val;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

int Cmp(const void *a, const void *b)
{
    if ((*(struct HashEntry *)a).val != (*(struct HashEntry *)b).val) {
        return (*(struct HashEntry *)b).val - (*(struct HashEntry *)a).val;
    } else {
        return (*(struct HashEntry *)a).key - (*(struct HashEntry *)b).key;    
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int i;
    int level;
    int *returnVal = (int *)malloc(k * sizeof(int));
    memset(returnVal, 0, k * sizeof(int));

    *returnSize = k;
    
    struct HashEntry *tmpHashEntry;
    for (i = 0; i < numsSize; i++) {
        level = nums[i];
        HASH_FIND_INT(g_this, &level, tmpHashEntry);
        if (tmpHashEntry == NULL) {
            tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            tmpHashEntry->key = level;
            tmpHashEntry->val = 1;
            HASH_ADD_INT(g_this, key, tmpHashEntry);
        } else {
            tmpHashEntry->val++;
        }
        //printf("key: %d, count: %d\n", tmpHashEntry->key, tmpHashEntry->val);
    }
    HASH_SORT(g_this, Cmp);
    
    struct HashEntry *orderHashEntry;
    orderHashEntry = g_this;
    int returnSizeIndex = 0;
    while ((orderHashEntry != NULL) && (returnSizeIndex < k)) {
        returnVal[returnSizeIndex] = orderHashEntry->key;
        //printf("after order: key: %d, count: %d\n", orderHashEntry->key, orderHashEntry->val);
        HASH_DEL(g_this, orderHashEntry);
        orderHashEntry = orderHashEntry->hh.next;
        returnSizeIndex++;
    }
    while (orderHashEntry != NULL) {
        HASH_DEL(g_this, orderHashEntry);
        orderHashEntry = orderHashEntry->hh.next;    
    }
    
    return returnVal;
}
```
