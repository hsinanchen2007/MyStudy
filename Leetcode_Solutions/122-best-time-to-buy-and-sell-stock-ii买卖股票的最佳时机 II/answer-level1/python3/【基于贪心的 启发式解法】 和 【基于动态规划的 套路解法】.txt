### 解题思路
基于贪心的 启发式解法
基于动态规划的 套路解法

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 法1：启发式：在所有上升的日期卖出今昨差值，在所有下降的日期不操作
        benefit = 0
        for i in range(1, len(prices)):
            benefit += max(prices[i]-prices[i-1], 0)
        #return benefit

        # 法2：动态规划
        # dp[i][j] 表示在第i天，持有的收益（已买入的股票为负收益）。其中，j表示是否持有股票，持有股票后续天才能卖出
        # 转移方程：
        #   dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])   表示由前一天 【不持有且没操作】 or 【持有且以prices[i]价格卖出】而来
        #   dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])   表示由前一天 【持有且没操作】 or 【不持有且以prices[i]价格买入】而来
        dp = [[0, 0] for _ in range(len(prices)+1)]
        # 边界状态(第0天)
        dp[0][0] = 0 # 肯定是未持有，收益0
        dp[0][1] = -2**31 # 不可能持有，收益负无穷 表示max不可选
        for i, v in enumerate(prices):
            dp[i+1][0] = max(dp[i][0], dp[i][1] + v)
            dp[i+1][1] = max(dp[i][1], dp[i][0] - v)
        return dp[-1][0] # 肯定不持有
```
基于贪心的 启发式解法
基于动态规划的 套路解法