### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 状态:天数. 
        # dp[i]:前i天的最大利润
        # 状态转移方程:dp[i] = max(dp[i-1],prices[i]-minPrice)
        if not prices:
            return 0
        maxProfit = 0
        minPrice = prices[0]
        for i in range(1,len(prices)):
            maxProfit = max(maxProfit,prices[i]-minPrice)
            minPrice = min(minPrice,prices[i])
        return maxProfit
```