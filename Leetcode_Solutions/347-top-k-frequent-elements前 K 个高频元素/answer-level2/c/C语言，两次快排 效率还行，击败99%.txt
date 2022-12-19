```
#define  MAX_SIZE 10000
struct Count {
    int index;
    int freq;
};
int Comp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}
int CompSt(void *a, void *b) {
    struct Count *x = a;
    struct Count *y = b;
    return (*y).freq - (*x).freq;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), Comp);
    struct Count count[MAX_SIZE] = {0};
    int m = 0;
    count[m].index = 0;
    count[m].freq = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count[m].freq++;
        } else {
            m++;
            count[m].index = i;
            count[m].freq = 1;
        }
    }
    m++;
    qsort(count, m, sizeof(count[0]), CompSt);
    int *res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = nums[count[i].index];
    }
    *returnSize = k;
    return res;
}

```
