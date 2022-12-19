理由：
直接用快速排序，因为要找的数的个数超过一半，所以最中间的那个数一定是。
```
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[(numsSize + 1) / 2 - 1];
}
```
