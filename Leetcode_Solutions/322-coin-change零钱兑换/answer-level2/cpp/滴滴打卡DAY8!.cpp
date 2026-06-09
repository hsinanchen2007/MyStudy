动态规划做法，以前做过又忘了。
关键是写出表达式和边界条件

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i)
                {dp[i] = min(dp[i-coins[j]] + 1, dp[i]);}
            }
        }
        cout<< dp[amount];
        return dp[amount] > amount ? -1:dp[amount];
    }
};
```