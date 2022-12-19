### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int INF = 2000000000;
        int *dp = new int[amount + 1];
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        fill(dp + 1, dp + amount + 1, INF);
        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j - coins[i - 1] >= 0)
                {
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
                }
            }
        }
        if (dp[amount] == INF)
        {
            return -1;
        }
        return dp[amount];
    }
};
```