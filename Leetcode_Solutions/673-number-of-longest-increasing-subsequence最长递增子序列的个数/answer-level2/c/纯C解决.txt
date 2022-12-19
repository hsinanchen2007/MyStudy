这道题其实和求最长递增子序列基本思路是一致的，本质区别就是在于通往最长递增子序列的道路有几条。所以这道题不会做的
建议先去做最长递增子序列。不然可能看不懂我的题解。

我举个例子，这道题其实就非常清晰了。这里用nums代表数组，**dp[i]代表以下标为i结尾的元素最长递增子序列的长度**。

nums:1 3 2 5 4 7
dp  :1 2 2 3 3 4

那么子序列有1357、1347、1257、1247

动态规划的核心在于找到状态转移方程。我们来分析一下，以7为结束的最长递增子序列的长度是4，那么通往7并且长度为4的道路上必然要经过长度为3并且 元素值小于7,毫无疑问就是4和5。那么状态就转移到了求通往4和5的最长递增子序列道路的数目。为了让大家看得更明白，并且更有利于解决这道题。我再加一个**max数组，记录通往下标为i的元素需要经过的前驱的数组**。那么可以得到。这里假设nums[-1]为负无穷大

nums:1 3 2 5 4 7
dp  :1 2 2 3 3 4
max :1,1,1,2,2,2

紧接着我们需要求的是那么状态就转移到了求通往某一个数的最长递增子序列道路的数目

那么就显然条件是nums[i]>nums[j]&&dp[i]==dp[j]+1,我们把长度dp[j]的max相加起来自然就是所有的道路了。
所以我这里第二次更新max数组。**这个时候max数组就由记录通往下标为i的元素需要经过的前驱的数组编程通往下标为i的元素需要经过的道路的数目了**。可得：
            nums:1 3 2 5 4 7
            dp  :1 2 2 3 3 4
max(第一次更新)) :1,1,1,2,2,2
max(第二次更新)) :1,1,1,2,2,4

最后把最长递增子序列的所有的道路数相加就是答案。
```
int findNumberOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int dp[numsSize],i,j;//dp[i]记录下标为i的元素最长连续子序列
    int max[numsSize];//max[i]记录路径数
    int countdp=1,countmax=0;
    for(i=0;i<numsSize;i++)//初始化
    {
        dp[i]=1;
        max[i]=1;
    }
    for (i=1;i<numsSize;i++)
        for(j=0;j<i;j++)
        if(nums[i]>nums[j])
        {
            if(dp[i]<dp[j]+1)//更新dp[i],更新max[i]
            {
                dp[i]=dp[j]+1;
                max[i]=1;
                if(dp[i]>countdp)
                countdp=dp[i];
            }
            else if(dp[i]==dp[j]+1)
            max[i]++;
        }
    for(i=1;i<numsSize;i++)
    {
        if(dp[i]>1)
        {
        max[i]=0;
        for(j=0;j<i;j++)
        if(nums[i]>nums[j]&&dp[i]==dp[j]+1)
        {
            max[i]+=max[j];
        }
        }
    }
    for(i=0;i<numsSize;i++)
    if(dp[i]==countdp)//最远长度
    countmax+=max[i];
    return countmax;
}
```

