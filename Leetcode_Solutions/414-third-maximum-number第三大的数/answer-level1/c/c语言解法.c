### 解题思路
先排序然后去重再找第三大的元素。

### 代码

```c
int cmp(int* a,int* b)
{
    return (*a)>(*b)?1:0;
}
int thirdMax(int* nums, int numsSize){
    int cnt=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i+1]!=nums[i])
        {
            nums[++cnt]=nums[i+1];
        }
    }
    if(cnt>=2)
    {
        return nums[cnt-2];
    }
    else
    {
        return nums[cnt];
    }
}
```