//找出出现次数最多的元素就是本题的解
//排序后，中位数必定是出现次数大于n/2的
```
int comp (const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    return nums[numsSize/2];
}
```
