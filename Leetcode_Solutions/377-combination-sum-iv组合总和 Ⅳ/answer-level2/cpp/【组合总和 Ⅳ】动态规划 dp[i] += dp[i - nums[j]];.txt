### 思路
1. 动态规划

### 答题
```cpp
int combinationSum4(vector<int>& nums, int target) 
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i < nums[j]) continue;
            dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
        }
    }
    return dp[target];
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

