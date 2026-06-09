1. 写出动态规划方程
dp[i]表示金额为i时，至少所需要的钱币数量，dp[i] = min(dp[i], dp[i-coin]+1) for coin in coins;
```C++ []
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        // for(int i=1; i<amount+1; i++)
        //     dp[i] = -1;
        for(int i=1; i<=amount; i++)
        {
            for(int coin :coins)
            {
               if(i>=coin)
               {
                //    if(dp[i] == -1)
                //         dp[i] = dp[i-coins[j]] + 1;
                //     else
                        dp[i] = min(dp[i], dp[i-coin] + 1);
               }
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];

    }
};
```

