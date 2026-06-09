### 解题思路
此处撰写解题思路

### 代码

```c
int compare(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}
int findRepeatNumber(int* nums, int numsSize){
    int *buk = (int*)calloc(numsSize,sizeof(int));
    qsort(nums,numsSize,sizeof(int),compare);
    int i;
    for(i = 0;i < numsSize;i++)
        buk[nums[i]]++;
    for(i = 0;i < nums[numsSize-1];i++)
    {
        if(buk[nums[i]] > 1)
        return nums[i];
    }
    return 0;
}
```