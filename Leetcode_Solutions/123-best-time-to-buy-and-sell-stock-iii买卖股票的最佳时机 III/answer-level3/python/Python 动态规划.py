定义四个状态, 每个存入历史最大收益
0. 手上有股票, 股票是第一次买入的
1. 手上没有股票, 股票是第一次卖出的
2. 手上有股票, 股票是第二次买入的
3. 手上没有股票, 股票是第二次卖出的

状态就是:
以cur[0, 1, 2, 3]表示当前的4个状态
pre[0, 1, 2, 3] 表示昨天的4个状态
p表示当前的票价,那么:

对于状态0, 可以存入迄今为止的最便宜票价
```
cur[0] = max {-p, pre[0]}
```
对于状态1, 判断是今天卖掉还是使用历史上某天卖出的结果

```
cur[1] = max{p + pre[0], pre[1]}
```

对于状态2, 只能通过pre[1]和pre[2]得到,判断是采用历史上第二次买入的结果,还是今天作为第二次买入

```
cur[2] = max{pre[2], pre[1] - p}
```

对于状态3,  判断采用历史上没有股票切第二次卖出的结果, 还是今天第二次卖出

```
cur[3] = max{pre[2] + p, pre[3]}
```


代码:

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        # [0 firstbuy, 1fsell, 2secondbuy, 3ssell]
        dp = [-prices[0], 0, float('-inf'), 0]
        for i in range(1, len(prices)):
            pre = dp[:]
            dp[0] = max(-prices[i], pre[0])
            dp[1] = max(prices[i] + pre[0], pre[1])
            dp[2] = max(pre[2], pre[1] - prices[i])
            dp[3] = max(pre[2] + prices[i], pre[3])
        return max(dp[1], dp[3]) 
```