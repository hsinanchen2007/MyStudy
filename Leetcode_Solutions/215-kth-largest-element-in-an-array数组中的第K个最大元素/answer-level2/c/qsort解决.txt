```
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int findKthLargest(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize == 0 || k == 0) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[k-1];
}
```
