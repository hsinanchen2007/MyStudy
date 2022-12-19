### 解题思路
整体思路是：遍历一遍数组，判断当前值该不该加到总和sum里。最朴素的思路出发。

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    if(numsSize==1)
        return nums[0];
    int sum=0,last,m,flag=0;;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>=0)
            flag=1;
    }
    if(flag==1)
    {
        for(last=0;last<numsSize;last++)
        {
            if(nums[last]>=0)
            {
             sum=nums[last];
             m=sum;
            break;
            }
        }
        for(int i=(last+1);i<numsSize;i++)
    {
        if(nums[i]>m)
            m=nums[i];
        if(nums[i]+sum<=0)
        {
            if(sum>m)
            {
                m=sum;
                sum=0;
            }
            else
            {
                sum=0;
            }
        }
        else
        {

            sum+=nums[i];
           // last=nums[i];
        if(sum>m)
            {
                m=sum;
            }
        }
    }
    return m;
    }
    else
    {
        sum=nums[0];
        m=sum;
         for(int i=1;i<numsSize;i++)
    {
        if(nums[i]>m)
            m=nums[i];
    }
    return m;
    }
}
```