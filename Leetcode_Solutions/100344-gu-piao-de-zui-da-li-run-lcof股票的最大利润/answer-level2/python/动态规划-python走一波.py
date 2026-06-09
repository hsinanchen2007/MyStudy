### 解题思路
动态规划，dp就是最低的买入点， 【7，1，1，1，1，1，】
pr就是每天的利润
max_p 是最大的利润
除去边界，完美解决

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        dp = [0]*len(prices)
        pr = [0]*len(prices)
        dp[0] = prices[0]
        pr[0] = 0
        max_p = 0
        for i in range(1, len(prices)):
            dp[i] = min(dp[i-1], prices[i])
            pr[i] = prices[i] - dp[i]
            max_p = max(max_p, pr[i])
        return max_p
```