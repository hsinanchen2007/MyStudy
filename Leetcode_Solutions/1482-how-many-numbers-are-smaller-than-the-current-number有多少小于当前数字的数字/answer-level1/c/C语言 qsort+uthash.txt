### 解题思路
qsort用于获得有效的 j 的数量
uthash用于是否已有记录
![image.png](https://pic.leetcode-cn.com/572577c20df8ad9ad5d5cce7a5c60d8e564456e90ee376be1aa8b4dd240b79f9-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

typedef struct {
    int num;
    int inx;
    int rltcnt;
    UT_hash_handle hh;
} MyItem;
typedef struct{
    MyItem *items;
    int itemsSize;
    MyItem *hh_item;
} MyStatus;
void sFree(MyStatus *s)
{
    int i;
    MyItem *item = NULL;
    MyItem *tmp = NULL;
    if (s->items == NULL) {
        return;
    }
    HASH_ITER(hh, s->hh_item, item, tmp) {
        HASH_DEL(s->hh_item, item);
    }
    free(s->items);
    s->items = NULL;
    return;
}
int sInit(MyStatus *s, int* nums, int numsSize)
{
    int i;
    s->itemsSize = numsSize;
    s->items = (MyItem*)calloc(s->itemsSize, sizeof(MyItem));
    if (s->items == NULL) {
        return MY_FAIL;
    }
    for (i = 0; i < numsSize; i++) {
        s->items[i].num = nums[i];
        s->items[i].inx = i;
        s->items[i].rltcnt = -1;
    }
    s->hh_item = NULL;
    return MY_OK;
}
int cmp(const void *a, const void *b)
{
    return ((MyItem*)a)->num > ((MyItem*)b)->num;
}
void proc(MyStatus *s, int *rlt, int* returnSize)
{
    int i;
    MyItem *item = NULL;
    qsort(s->items, s->itemsSize, sizeof(MyItem), cmp);
    for (i = 0; i < s->itemsSize; i++) {
        HASH_FIND_INT(s->hh_item, &(s->items[i].num), item);
        if (item == NULL) {
            s->items[i].rltcnt = i;
            rlt[s->items[i].inx] = i;
            HASH_ADD_INT(s->hh_item, num, (&s->items[i]));
        } else {
            rlt[s->items[i].inx] = item->rltcnt;
        }
    }
    *returnSize = s->itemsSize;
    return;
}
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int ret;
    MyStatus s;
    int *rlt = NULL;
    if (nums == NULL || numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    rlt = (int*)calloc(numsSize, sizeof(int));
    if (rlt == NULL) {
        *returnSize = 0;
        return NULL;
    }
    ret = sInit(&s, nums, numsSize);
    if (ret != MY_OK) {
        free(rlt);
        *returnSize = 0;
        return NULL;
    }
    proc(&s, rlt, returnSize);
    sFree(&s);
    return rlt;
}
```