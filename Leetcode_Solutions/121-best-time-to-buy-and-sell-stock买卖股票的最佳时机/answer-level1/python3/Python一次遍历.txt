### 解题思路
进行一次遍历，如果该点的值小于最小值，则后续点与其的差值一定大于与原最小值的差。因此更新最小值。
再比较该点与最小值的差值，大于之前的最大利润则进行更新。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        
        if n == 0 or n == 1:
            return 0
        
        min_price = prices[0]
        profit = 0
        for i in range(1,n):
            if prices[i] < min_price:
                min_price = prices[i]
            if prices[i] - min_price > profit:
                profit = prices[i] - min_price
        
        return profit
        
```