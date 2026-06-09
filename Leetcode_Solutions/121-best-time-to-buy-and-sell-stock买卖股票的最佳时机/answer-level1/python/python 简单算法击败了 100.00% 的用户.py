### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        def max_profit(arr):
            min_price = arr[0] if arr else 0
            profit = 0
            for i in arr:
                min_price = min(i, min_price)
                profit = max(i-min_price, profit)
            return profit

        return max_profit(prices)

```