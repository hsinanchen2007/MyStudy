思路是把每天分成五个状态:
1. 买入
2. 卖出
3. 冷冻期
4. 手上有股票
5. 手上没有股票
维持截止目前为止每个状态的最大值
那么:
```
今天买入: 昨天手上没有股票 - 今天股票价格
今天卖出: max(昨天买入, 昨天手上有股票) + 今天股票价格
今天冷冻期: 昨天卖出
今天手上有股票: max(今天买入, 昨天手上有股票)
今天手上没有股票: max(昨天卖出, 昨天冷冻期, 手上没有股票)
```



```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        # dp [buy sell cooldown havestock nothavstock]
        dp = [-prices[0], 0, float('-inf'), -prices[0], 0]
        for i in range(1, len(prices)):
            pre = dp[:]
            price = prices[i]
            dp[0] = pre[4] - price
            dp[1] = max(pre[0], pre[3]) + price
            dp[2] = pre[1]
            dp[3] = max(dp[0], pre[3])
            dp[4] = max(pre[1], pre[2], pre[4])
        return max(dp[1], dp[2], dp[4])
```