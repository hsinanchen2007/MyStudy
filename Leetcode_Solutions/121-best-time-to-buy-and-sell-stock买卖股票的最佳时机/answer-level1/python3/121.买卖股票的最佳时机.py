### 解题思路
### 代码
```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)<=1:
            return 0
        min_prices=prices[0]
        max_profit=0
        for i in range(len(prices)):
            if prices[i]<=min_prices:   #寻找数组prices中的最小价格
                min_prices=prices[i]
            if prices[i]-min_prices>max_profit:
                max_profit=prices[i]-min_prices
        return max_profit
```