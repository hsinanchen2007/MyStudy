### 解题思路
升判利，降判基。一重循环。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        pre = prices[0]
        base = prices[0]
        profit = 0
        for val in prices:
            if val > pre:
                profit = max(profit,val - base)
            if val < pre:
                base = min(base,val)
            pre = val
        return profit
```