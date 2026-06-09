### 解题思路
因为可以同时买出买入（当天卖了当天又买），要获得最大收益，只用保证每笔都赚钱就行
即prices[i-1]<prices[i]
e.g 把题目当成简单的数学问题去计算最大值就好，不懂就画图。不要被题干代入成文字理解题。
### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxprofit = 0
        for i in range(1,len(prices)):
            if prices[i-1] < prices[i]:
                maxprofit += prices[i] - prices[i-1]
        return maxprofit

```