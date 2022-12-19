### 解题思路
我建议不太懂背包问题的伙伴先去看一下什么是01背包，然后我觉得你在来看我的思路就会很清晰了。

这道题其实是01背包的经典变形，我们要判断是否能够分成两个子数组，且和相等，那么我们就把我们的背包的容量设置为数组总和的一半，如果我们能够确保我们最后能够放入的背包价值和子数组和的一半恰好相等，毫无疑问那么就是可以分割。

这里写了从二维数组转一维的代码，空间复杂度减少

### 代码


```c
//二维数组
bool canPartition(int* nums, int numsSize){
    int bag=0;
    int i;
    for(i=0;i<numsSize;i++)
    bag+=nums[i];
    if(bag%2!=0)//总数和不是偶数
    return false;
    bag/=2;//确定背包大小

    int dp[numsSize+1][bag+1];
    int j;
    
    for(i=0;i<=numsSize;i++)
        for(j=0;j<=bag;j++)
        {
            if(i==0||j==0)//初始化
            dp[i][j]=0;
            else//状态转移方程
            {
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0&&dp[i-1][j-nums[i-1]]+nums[i-1]>dp[i][j])//容量够并且还更大
                dp[i][j]=dp[i-1][j-nums[i-1]]+nums[i-1];
            }
        }
    if(dp[numsSize][bag]==bag)
    return true;
    return false;
}

```



```c
//一维数组
bool canPartition(int* nums, int numsSize){
    int bag=0;
    int i;
    for(i=0;i<numsSize;i++)
    bag+=nums[i];
    if(bag%2!=0)//总数和不是偶数
    return false;
    bag/=2;//确定背包大小

    int dp[bag+1];
    int j;
    for(j=0;j<=bag;j++)//初始化
    dp[j]=0;
    for(i=0;i<numsSize;i++)
        for(j=bag;j>=nums[i];j--)
        {
                dp[j]=dp[j]>dp[j-nums[i]]+nums[i]?dp[j]:dp[j-nums[i]]+nums[i];
        }
    if(dp[bag]==bag)
    return true;
    return false;
}
```