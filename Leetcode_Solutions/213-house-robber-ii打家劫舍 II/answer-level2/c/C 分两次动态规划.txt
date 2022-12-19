![Snipaste_2020-03-18_14-29-28.jpg](https://pic.leetcode-cn.com/34d74b2099c2873f88093e9856e5ccc93fdbfbb7ca76ee81b70faae586ad3c8d-Snipaste_2020-03-18_14-29-28.jpg)

### 解题思路
既然首尾元素不能同时选，那就分两次动态规划，第一次剔除尾元素，第二次剔除首元素，最后比较两次动态规划得到的最大值

### 代码

```c
int rob(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    int* dp = (int*)malloc(sizeof(int)*numsSize);
    int res1 = 0, res2 = 0;
    dp[0] = nums[0];
    dp[1] = nums[1]>nums[0]?nums[1]:nums[0];
    for(int i = 2; i < numsSize-1; i++)//最后一个元素不纳入动态规划
    {
        if(dp[i-2] + nums[i] > dp[i-1])
            dp[i] = dp[i-2] + nums[i];
        else
            dp[i] = dp[i-1];
    }
    res1 = dp[numsSize-2];
    
    dp[1] = nums[1];//去掉首元素需重置
    dp[2] = nums[2]>nums[1]?nums[2]:nums[1];
    for(int i = 3; i < numsSize; i++)//第一个元素不纳入动态规划
    {
        if(dp[i-2] + nums[i] > dp[i-1])
            dp[i] = dp[i-2] + nums[i];
        else
            dp[i] = dp[i-1];
    }
    res2 = dp[numsSize-1];
    
    return res1>res2?res1:res2;
}
```