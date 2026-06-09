### 解题思路
动态规划状态机：dp[i][k][1]/dp[i][k][0]表示第i天剩k次交易机会的时候持有/没持有股票
当天持有可能是前一天持有或者今天买入：dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-price[i])
当前没持有可能是前一天没持有或者今天卖出：dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+price[i])
初始状态，i=-1时还没开始，利润为0：dp[-1][k][0] = 0，不可能持有dp[-1][k][1] = -inf
初始状态，k=0没有交易机会，利润为0：dp[i][0][0] = 0，不可能持有dp[i][0][1] = -inf
最终返回，最后一天卖出得到的利润：dp[n-1][K][0]

本题有无限次交易机会，k=inf，不用考虑k的变化
本题有一天冷冻期，当天买入的时候，前两天都没有持有
dp[i][1] = max(dp[i-1][1], dp[i-2][0]-price[i])
dp[i][0] = max(dp[i-1][0], dp[i-1][1]+price[i])
dp[-1][0] = 0，dp[-1][1] = -inf，dp[-2][0] = 0

### 代码

```python3
class Solution:
    def maxProfit(self, prices):
 

        # dp = [[0 for _ in range(2)] for _ in range(len(prices))]
        # 每个状态都只跟前两个状态有关，优化空间到O(1)
        dp_i_1 = -float('inf')
        dp_i_0 = 0
        dp_i2_0 = 0

        for i in range(len(prices)):
            tmp = dp_i_0
            dp_i_1 = max(dp_i_1, dp_i2_0 - prices[i])
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i2_0 = tmp

        return dp_i_0
        
```