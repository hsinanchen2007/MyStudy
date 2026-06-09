```
int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
void wiggleSort(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int left = (numsSize % 2 ? numsSize / 2 : numsSize / 2 - 1);
    int right = numsSize - 1;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2) {
            ret[idx++] = nums[right--];
        } else {
            ret[idx++] = nums[left--];
        }
    }
    memcpy(nums, ret, sizeof(int) * numsSize);
}
```
