### 解题思路
一眼懂

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 1:
            return 0
        res = 0
        for i in range(len(prices)-1):
            if prices[i+1]-prices[i] > 0:
                res += (prices[i+1]-prices[i])
        return res
```