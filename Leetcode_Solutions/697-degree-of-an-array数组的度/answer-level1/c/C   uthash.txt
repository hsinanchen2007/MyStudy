用uthash写的，设计数据结构时包含数字第一次出现的位置和最后一次出现的位置，数字出现的次数

```
typedef struct tagHashNode {
    int id;
    int cnt;
    int start;
    int end;
    UT_hash_handle hh;
}HashNode;

int findShortestSubArray(int* nums, int numsSize){
    HashNode *hash_table = NULL;
    HashNode *item = NULL;
    int maxCnt = 1;
    for (int i = 0; i < numsSize; ++i) {
        int tmp = nums[i];
        HASH_FIND_INT(hash_table, &tmp, item);
        if (item == NULL) {
            item = (HashNode *)calloc(1, sizeof(HashNode));
            item->id = tmp;
            item->cnt = 1;
            item->start = i;
            item->end = i;
            HASH_ADD_INT(hash_table, id, item);
        } else {
            item->cnt++;
            item->end = i;
            maxCnt = (maxCnt < item->cnt) ? item->cnt : maxCnt;
        }
    }
    HashNode *cur = NULL;
    HashNode *tmp = NULL;
    int minSize = numsSize;
    HASH_ITER(hh, hash_table, cur, tmp) {
        if (cur->cnt == maxCnt) {
            minSize = (cur->end - cur->start + 1) < minSize ? (cur->end - cur->start + 1) : minSize;
        }
        HASH_DEL(hash_table, cur);
        free(cur);
    }
    return minSize;
}
```
