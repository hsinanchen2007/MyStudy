### 解题思路
使用动态规划, 首先将数组`dp`初始化为`amount+1`, 长度为`amount+1`, `dp[i]`的含义为凑成`i`最少需要的硬币数, 其递推关系为:
$$
dp[i]=\min_{j, coins[j]\le i}{dp[i-coins[j]]+1}.
$$
另外, 由上述递推关系可知, 若无法凑成`i`, 由初始化的操作可知`dp[i]=amount+1`.

### 代码
```
#define MIN(a, b) ((a)<(b)?(a):(b))
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
            for(int j = 0; j < coins.size(); j++)
                if(coins[j]<=i)
                    dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```