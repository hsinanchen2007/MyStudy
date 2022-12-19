### 解题思路
dp[i] 为第i天卖出股票的最大利润
则 有两选择 一个是我前一天没有卖股票，则在前一天的利润基础上加上最新的收益or亏损，另一种是当天买当天卖，收益为0
则 dp[i]= max(dp[i-1]+prices[i]-prices[i-1],0)

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [0]
        for i in range(1,len(prices)):
            dp.append(max(dp[i-1]+prices[i]-prices[i-1],0))
        return max(dp)
                
            
```