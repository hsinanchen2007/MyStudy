
```python
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        # 每个元祖表示当前持有股票以及不持有股票时所能最大化的自己的余额
        temp = (-prices[0], 0)  # 对第一个股价，若持有时余额为负股票价，不持有时为0
        if len(prices) == 1:
            return max(temp)
        dp = [temp]
        # 持有时余额最大为前两天最低价买入的情况，不持有时为一直不买和一买二卖中的最大值
        temp = (-min(prices[0], prices[1]), max(0, prices[1] - prices[0]))
        dp.append(temp)
        # 持有时考虑保持前一天的持有和前两天不持有现在买入时的情况，不持有时考虑保持前一天的不持有和前一天持有现在卖出时的情况
        for p in prices[2:]:
            temp = (max(dp[1][0], dp[0][1] - p), max(dp[1][1], dp[1][0] + p))
            dp[:] = [dp[1], temp]
        return max(dp[1])
```
