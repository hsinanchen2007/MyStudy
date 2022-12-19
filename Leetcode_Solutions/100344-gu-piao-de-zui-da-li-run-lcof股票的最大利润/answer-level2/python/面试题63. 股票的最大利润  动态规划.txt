### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        if not prices:return 0
        dp = [0] * len(prices)
        for i in range(1,len(prices)):
            dp[i] = max(0,dp[i-1]+prices[i]-prices[i-1])
        return max(dp)
```