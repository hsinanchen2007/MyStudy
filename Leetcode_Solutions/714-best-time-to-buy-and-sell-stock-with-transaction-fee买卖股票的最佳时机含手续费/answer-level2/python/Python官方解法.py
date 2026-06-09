```
class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        我们维护两个变量 cash 和 hold，前者表示当我们不持有股票时的最大利润，后者表示当我们持有股票时的最大利润。

        在第 i 天时，我们需要根据第 i - 1 天的状态来更新 cash 和 hold 的值。对于 cash，我们可以保持不变，或者将手上的股票卖出，状态转移方程为

        cash = max(cash, hold + prices[i] - fee)
        对于 hold，我们可以保持不变，或者买入这一天的股票，状态转移方程为

        hold = max(hold, cash - prices[i])
        在计算这两个状态转移方程时，我们可以不使用临时变量来存储第 i - 1 天 cash 和 hold 的值，而是可以先计算 cash 再计算 hold，原 
        因是在同一天卖出再买入（亏了一笔手续费）一定没不买好。
        """
        
        cash, hold = 0, -prices[0]
        for i in range(1, len(prices)):
            cash = max(cash, hold + prices[i] - fee)
            hold = max(hold, cash - prices[i])
        return cash
```
