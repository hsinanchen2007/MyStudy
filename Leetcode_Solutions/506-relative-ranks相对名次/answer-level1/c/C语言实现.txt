先排序，再输出。
```
typedef struct _Data{
    int index;
    int val;
} Data;

int cmp(const void *a, const void *b){
    return ((Data*)b)->val - ((Data*)a)->val;
}

char ** findRelativeRanks(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;
    Data *d = (Data*)malloc(numsSize * sizeof(Data));
    int i;
    for (i = 0; i < numsSize; ++i) {
        d[i].index = i;
        d[i].val = nums[i];
    }
    qsort(d, numsSize, sizeof(Data), cmp);
    char **res = (char**)malloc(numsSize * sizeof(char*));
    memset(res, 0, numsSize * sizeof(char*));
    for (i = 0; i < numsSize; ++i){
        res[d[i].index] = (char*)malloc(13 * sizeof(char));
        memset(res[d[i].index], 0, 13 * sizeof(char));
        switch (i) {
        case 0:
            sprintf(res[d[i].index], "Gold Medal");
            break;
        case 1:
            sprintf(res[d[i].index], "Silver Medal");
            break;
        case 2:
            sprintf(res[d[i].index], "Bronze Medal");
            break;
        default:
            sprintf(res[d[i].index], "%d", i + 1);
            break;
        }
    }
    return res;
}
```
