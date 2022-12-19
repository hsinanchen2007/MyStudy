### 解题思路
定义sum和count分别记录最大值和当前的值默认为数组第0个元素值。遍历数组，如果count小于0说明之前的连续和一定不是最大的，让count从当前位置重新计算，如果count>sum 更新sum。

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int i,sum,count;
    sum=nums[0];
    count = nums[0];
    for(i=1;i<numsSize;i++)
    {
        if(count<0)
            count = nums[i];
        else
            count+=nums[i];
        if(count > sum)
            sum=count;
            
    }
    return sum;
}
```