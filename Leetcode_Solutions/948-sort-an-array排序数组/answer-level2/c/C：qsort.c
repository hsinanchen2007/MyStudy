思路：
直接qsort后返回malloc的数组
```
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        res[i] = nums[i];
    }
    qsort(res, *returnSize, sizeof(int), compare);
    return res;
}
```
