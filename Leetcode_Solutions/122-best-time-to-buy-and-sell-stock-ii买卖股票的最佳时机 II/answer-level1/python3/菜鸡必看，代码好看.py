### 解题思路
好奇为什么股票没有medium

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1 :
            return 0
        dp=[0]
        for i in range(1,len(prices)) :
            if prices[i]<=prices[i-1] :
                dp+=[0]
            else :
                dp+=[prices[i]-prices[i-1]]
        return sum(dp)
```