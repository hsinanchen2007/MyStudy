### 解题思路
此处撰写解题思路

### 代码

```c
int compare(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize,sizeof(int), compare);
    return nums[numsSize-k];
}
```