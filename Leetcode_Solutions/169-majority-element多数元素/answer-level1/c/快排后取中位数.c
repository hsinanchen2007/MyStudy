### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
}
int majorityElement(int* nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    return nums[numsSize/2]; 
}
```