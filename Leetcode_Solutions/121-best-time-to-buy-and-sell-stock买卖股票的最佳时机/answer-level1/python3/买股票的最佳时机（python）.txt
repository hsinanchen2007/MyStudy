### 解题思路
（1）记录prices中前面的最小价格Min，作为买入价格
（2）将当前的价格作为售出价格，并确定是否为最大收益


### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n=len(prices)
        if n==0:
            return 0
        Min=prices[0]
        Max=0
        if n==0:
            return 0
        for i in range(1,n):
            if Min>prices[i]:
                Min = prices[i]
            else:
                Max=max(Max,prices[i]-Min)
        return Max
```