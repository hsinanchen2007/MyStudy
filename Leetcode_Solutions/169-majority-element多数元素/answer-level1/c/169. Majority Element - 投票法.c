### 解题思路
如果一个元素符合主要元素的要求,那么这个元素的得票数一定大于其他所有元素得票数之和.
我们假设这个数组里面的不同元素作为这场竞选的候选人,当数组中出现这个元素的时候,就可以认为有人给这个元素投票.
如果有不同元素的得票,那么就消耗这个元素原有的票数,由第一句话可知
最后count>0的元素一定是主要元素.

### 代码

```c
int majorityElement(int* nums, int numsSize)
{
    // 设置两个变量 一个叫做candidate,一个叫做count
    int candidate=nums[0], count=1, i;
    for(i=1; i<numsSize; i++)
    {
        if(candidate == nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if(count<0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}
```