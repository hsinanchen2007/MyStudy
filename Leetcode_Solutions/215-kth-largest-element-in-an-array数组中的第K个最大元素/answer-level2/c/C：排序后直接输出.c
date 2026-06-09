思路：
qsort从大到小排序后直接输出array[k-1];
```
int compare(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[k-1];
}
```
