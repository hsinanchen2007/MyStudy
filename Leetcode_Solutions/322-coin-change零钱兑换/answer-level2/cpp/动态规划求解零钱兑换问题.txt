### 解题思路
自下而上的动态规划
![捕获.JPG](https://pic.leetcode-cn.com/7b3f816992e5323fda28e92c7b3a107c64f42ee9dc3bd67e5513796e9668692e-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```cpp
class Solution {
public:
    // 自下而上的动态规划：dp[i] = min(dp[i - cj]) + 1; j=0,1,...,coins.size()-1
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount? -1: dp[amount];
    }
};
```