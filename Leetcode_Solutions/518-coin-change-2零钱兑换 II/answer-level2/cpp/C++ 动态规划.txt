# 解法一：
可以看作是背包问题
1，`dp[i][j]`代表仅利用前`i`种(从1开始数起)钱币能组成和为`j`的情况数
2，状态转移方程为：
`dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];`

```C++ []
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<long> > dp(N + 1, vector<long>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j] + ((j >= coins[i - 1]) ? dp[i][j - coins[i - 1]] : 0);
            }
        }
        return dp[N][amount];
    }
};
```
![image.png](https://pic.leetcode-cn.com/ff2e6c3fc576b519da3838a1baa745040cce88bb0a945e36d1dea4237e3c8f56-image.png)


# 解法二：
状态压缩动态规划
效率更高，空间更少
```C++ []
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i - 1]];
            }
        }
        return dp[amount];
    }
};
```

![image.png](https://pic.leetcode-cn.com/92bcfef87957cfb70a1ddd0620ec8ac82c8a60d160b0da74942c79bf02679959-image.png)
