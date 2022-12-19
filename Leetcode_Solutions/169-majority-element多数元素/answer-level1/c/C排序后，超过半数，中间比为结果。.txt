```
int cmp(const void *a, const void *b){
    const int l = *(int*)a;
    const int r = *(int*)b;
    return l - r;
}
int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize/2];
}
```
