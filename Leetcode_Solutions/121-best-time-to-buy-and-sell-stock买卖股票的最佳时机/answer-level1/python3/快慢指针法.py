### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
      if not prices:
        return 0
      maxP = 0
      minV = prices[0]
      for i in range(1,len(prices)):
        maxP = max(prices[i] - minV,maxP)
        minV = min(minV,prices[i])
      return maxP
```