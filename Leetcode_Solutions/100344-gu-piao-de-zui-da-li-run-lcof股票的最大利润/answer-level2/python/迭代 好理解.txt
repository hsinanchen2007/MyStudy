### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2:
            return 0
        min_price=prices[0]
        maxprofit=0
        for i in range(len(prices)):
            min_price=min(prices[i],min_price)
            maxprofit=max(maxprofit,prices[i]-min_price)
        return maxprofit
            
```