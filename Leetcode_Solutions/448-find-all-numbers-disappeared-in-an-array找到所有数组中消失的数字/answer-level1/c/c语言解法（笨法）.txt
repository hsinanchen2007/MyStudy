### 解题思路
方法很笨很好理解。
先排序然后去重，然后按数存到对应的位置。再比较。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int* a,int* b)
{
    return *a>*b?1:0;
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    if(numsSize==0)
    {
        *returnSize=0;
        return nums;
    }
    int flag=0;
    int cnt=1,cmt=0;
    int* num=(int*)calloc(sizeof(int),numsSize);
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i+1]!=nums[i])
        {
            nums[cnt++]=nums[i+1];
        }
    }
    for(int i=0;i<cnt;i++)
    {
        num[nums[i]-1]=nums[i];
    }
    for(int i=1;i<numsSize+1;i++)
    {
        if(num[i-1]!=i)
        {
            num[cmt++]=i;
        }
    }
    *returnSize=cmt;
    return num;
}
```