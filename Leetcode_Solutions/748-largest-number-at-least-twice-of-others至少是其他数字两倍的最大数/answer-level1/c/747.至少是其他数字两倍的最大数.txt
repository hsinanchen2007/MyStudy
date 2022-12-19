### 解题思路
暴力求解，简单计算，额。考虑特殊情况，再考虑判定元素中的最大值以及元素最大值应满足的条件。显然，我这种方法就比较笨了。

### 代码

int dominantIndex(int* nums, int numsSize){
    int max=0,t=0;
    if(nums==NULL)
    {
        return -1;
    }
    if(numsSize==1)
    {
        return 0;
    }
    for(int i=0;i<numsSize;i++)
    {
        if(max<nums[i])
        {
            max=nums[i];
            t=i;
        }
    }
    for(int i=0;i<numsSize;i++)
    {
        if(i!=t&&max<nums[i]*2)
        {
            return -1;
        }
    }
    return t;

}
```