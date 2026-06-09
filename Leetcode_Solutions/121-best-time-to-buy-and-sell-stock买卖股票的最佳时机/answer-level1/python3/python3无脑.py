### 解题思路
就遍历一遍，取剩下里面最大的，算差值。再比较取差值最大的。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for buy_day in range(0, len(prices)-1):
           sell = max(prices[buy_day+1:])
           profit = sell - prices[buy_day]
           if profit > max_profit:
               max_profit = profit
        return max_profit


```