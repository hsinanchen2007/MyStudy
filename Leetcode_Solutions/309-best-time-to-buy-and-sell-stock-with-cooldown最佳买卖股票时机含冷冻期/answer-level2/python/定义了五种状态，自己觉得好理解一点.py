定义了五种状态，看其他解法都是三种，有点想不明白，求解释为什么不需要 不操作的状态？  

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        BUY=0
        SELL=1
        COOLDOWN=2
        NONE_BUY=3    #已经持有且不操作
        NONE_NOTBUY=4 #没有持有且不操作
        
        #建立初始状态
        dp = [[0,0,0,0,0] for i in range(len(prices))]
        dp[0][BUY] = -prices[0]
        dp[0][SELL] = 0
        dp[0][COOLDOWN] = 0
        dp[0][NONE_BUY] = -prices[0] #这种情况等于第一天买了
        dp[0][NONE_NOTBUY] = 0
        
        for i in range(1,len(prices)):
            #如果买入，那么前一天有两种情况：冷冻期 或 没有持有且不操作
            dp[i][BUY] = max([dp[i-1][COOLDOWN]-prices[i], dp[i-1][NONE_NOTBUY]-prices[i]])
            #如果卖出，那么前一天有两种情况：买入 或 已经持有且不操作
            dp[i][SELL] = max([dp[i-1][BUY] + prices[i], dp[i-1][NONE_BUY] + prices[i]])
            #如果是冷冻期，说明前一天一定是卖出的
            dp[i][COOLDOWN] = dp[i-1][SELL]
            #如果是已经持有且不操作，那么前一天有两种情况：买入 或 已经持有且不操作
            dp[i][NONE_BUY] = max([dp[i-1][BUY], dp[i-1][NONE_BUY]])
            #如果是没有持有且不操作，那么前一天有两种情况：冷冻期 或 没有持有且不操作
            dp[i][NONE_NOTBUY] = max([dp[i-1][COOLDOWN],dp[i-1][NONE_NOTBUY]])
        return max(dp[-1][SELL], dp[-1][COOLDOWN], dp[-1][NONE_NOTBUY])
```