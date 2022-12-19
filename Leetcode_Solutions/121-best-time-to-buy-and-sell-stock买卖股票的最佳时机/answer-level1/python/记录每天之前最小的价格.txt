### 解题思路
记录每天之前最小的价格，这样就可以遍历一次找到最佳收益
双层遍历 由于是python写的会超时

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        profit = 0
        if length > 0:
            min_price = prices[0]  
            for i in range(1, length):
                if prices[i] - min_price > profit:
                    profit = prices[i] - min_price
                elif prices[i] - min_price <= profit and prices[i] > min_price:
                    continue
                else:
                    min_price = prices[i]
            
        return profit

```