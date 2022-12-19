### 解题思路
Hash 解法
排序解法

### 代码

【排序】
```
int Comp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int CompHash(void *a, void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    
    return pb[1] - pa[1];
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    /* 总体思路：利用二维数组建立数字和出现次数的映射；key为num
    通过将数据进行排序，则会获取对应的key */
    int *ans = (int *)malloc(sizeof(int) * k);
    int **hash = (int **)calloc(1, sizeof(int *) * numsSize);
    int index = 0;
    int i;
    
    for (i = 0; i < numsSize; i++) {
        hash[i] = (int *)calloc(1, sizeof(int) * 2);
    }
    
    qsort(nums, numsSize, sizeof(int), Comp);
    hash[0][0] = nums[0];
    hash[0][1] = 1;
    index++;
    for (i = 1; i < numsSize; i++) {
        if (hash[index - 1][0] == nums[i]) {
            hash[index - 1][1]++;
        }else {
            hash[index][0] = nums[i];
            hash[index][1] = 1;
            index++;
        }
    }
    
    qsort(hash, numsSize, sizeof(int) * 2, CompHash);
    
    for (i = 0; i < k; i++) {
        ans[i] = hash[i][0];
    }
    
    for (i = 0; i < numsSize; i++) {
        free(hash[i]);
    }
    free(hash);
    *returnSize = k;
    return ans;
}
```


【uthash】
```c
//#include "uthash.h"

struct HashEntry {
    int key;
    int cnt;
    UT_hash_handle hh;
};

static struct HashEntry *g_users;

static void AddNum(int key)
{
    struct HashEntry *p;

    HASH_FIND_INT(g_users, &key, p);
    if (p == NULL) {
        p = (struct HashEntry *)calloc(1, sizeof(struct HashEntry));
        p->key = key;
        p->cnt = 1;
        HASH_ADD_INT(g_users, key, p);
    } else {
        p->cnt++;
    }
}

static int Comp(struct HashEntry *a, struct HashEntry *b)
{
    if (a->cnt == b->cnt) {
        return a->key - b->key;
    }
    return b->cnt - a->cnt;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int i, ansIndex;
    struct HashEntry *cur, *tmp;
    int *ans = (int *)calloc(1, sizeof(int) * k);

    g_users = NULL;
    for (i = 0; i < numsSize; i++) {
        AddNum(nums[i]);
    }
    HASH_SORT(g_users, Comp);
    ansIndex = 0;
    HASH_ITER(hh, g_users, cur, tmp) {
        if (ansIndex < k) {
            ans[ansIndex++] = cur->key;
        } else {
            break;
        }
    }
    *returnSize = k;
    return ans;
}
```