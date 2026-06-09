考虑股票只短线日结，如果明天收益比今天高就买，反之不买
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        grid = 0
        for i in range(len(prices) - 1):
            if prices[i + 1] > prices[i]:
                grid += prices[i + 1] - prices[i]
        return grid
```
