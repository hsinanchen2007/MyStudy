### 解题思路
dp[i]表示coins凑成i需要的最少硬币个数

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) continue;
                if (dp[i - coins[j]] == -1) continue;
                dp[i] = dp[i] == -1 ? 1 + dp[i - coins[j]] : min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount];
    }
};
```