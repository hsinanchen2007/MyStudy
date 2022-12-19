动态规划解法
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if (len(prices)<=1):
            return 0
        min_p=prices[0]
        max_p=0
        for i in range(len(prices)):
            min_p= min(min_p,prices[i])
            max_p= max(max_p,prices[i]-min_p)
        return max_p
```

最大利润=max{前一天最大利润, 今天的价格 - 之前最低价格}
