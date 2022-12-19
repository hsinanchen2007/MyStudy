### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==0: return 0
        prev = prices[0]
        maxprofit = 0
        maxhere = 0
        for i in prices[1:]:
            x = i - prev
            prev = i
            maxhere = maxhere + x if maxhere > 0 else x
            maxprofit = max(maxprofit, maxhere)
        return maxprofit
```