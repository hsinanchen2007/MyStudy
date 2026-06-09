### 解题思路
价格依次取（当前的-过去的最低价）然后取价格的最高

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        total = 0
        for i in range(1,len(prices)):
            mi = min(prices[0:i])
            if prices[i]>mi:
                total = max(prices[i] - mi,total)
            else: 
                pass
        return total
                
```