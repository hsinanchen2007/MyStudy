**方法1  动态规划：**

首先明确dp数组所存数据的含义。我们定义dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度。
根据数组的定义，运用数学归纳法的思想，由已知的dp[0,1... ,i-1]，求出dp[i]。

对于dp[i]的求解：
在nums数组中，位置 i 之前找到nums值小于nums[i]的位置 j ，在 j 位置这个最长递增子序列的基础上加上nums[i]，所以dp[i]的值就是在dp[i]和dp[j]+1两者中间取最大值。
时间复杂度为O(n)。

```
int max(int a,int b)
{
    return a>b?a:b;
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;//在用函数参数作为数组维度之前，对参数特殊情况（numsSize == 0）做处理
    int dp[numsSize];//定义dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度
    for(int i = 0;i < numsSize;++i)
        dp[i] = 1;//dp数组初始化为1，因为最长递增子序列最短都是1（包括nums此位置上的那个数）
    for(int i = 0;i < numsSize;++i){
        for(int j = 0;j < i;++j){
            if(nums[j] < nums[i])
                dp[i] = max(dp[i],dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0;i < numsSize;++i)
        ans = max(ans,dp[i]);//dp数组中的最大值就是最长递增子序列的长度
    return ans;
}
```


# 方法二  二分查找

二分查找方法作为一种扩展吧，用动态规划搞定就不错了。

```
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize <= 0)
        return 0;
    int top[numsSize];
    int cnt = 0;
    for(int i = 0;i < numsSize;++i){
        int left = 0,right = cnt;
        while(left < right){
            int mid = (left + right) >> 1;
            if(top[mid] >= nums[i])
                right = mid;
            else
                left = mid + 1;
        }
        if(left == cnt)
            ++cnt;
        top[left] = nums[i];
    }
    return cnt;
}
```
