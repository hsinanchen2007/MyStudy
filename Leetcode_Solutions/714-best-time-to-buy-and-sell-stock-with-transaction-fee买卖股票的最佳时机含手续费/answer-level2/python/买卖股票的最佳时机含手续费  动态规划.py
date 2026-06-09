### 解题思路
维护两个数组dp1[i]和dp2[i]，其中dp1[i]表示持有股票获得最大的利润，dp2[i]表示未持有股票时当天的最大利润
但是其实我是有疑问的，就是此题是否满足当天卖出当天买入？

### 代码

```python
class Solution(object):
    def maxProfit(self, prices, fee):
        if not prices:return 0
        dp1 = [0] * len(prices)#持有股票利润
        dp2 = [0] * len(prices)#未持有利润
        dp1[0] = -prices[0]
        for i in range(1,len(prices)):
            dp1[i] = max(dp1[i-1],dp2[i-1] - prices[i])
            dp2[i] = max(dp2[i-1],dp1[i-1] + prices[i] - fee)
        return dp2[-1]
```