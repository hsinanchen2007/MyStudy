**代码：**
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if l==0 or l==1:
            return 0
        buyin = float('inf')
        profit = 0
        flag = 0
        for i in range(l-1):
            if prices[i]<prices[i+1] and prices[i]<buyin: //可以买入
                buyin = prices[i] //买入时的价格
                flag = 1 //已有交易的标志         
            elif prices[i]>prices[i+1] and flag==1:
                profit += prices[i] - buyin //卖出所得的利润
                flag = 0 //标志清零
                buyin = float('inf')
            if flag==1 and i+1==l-1 and prices[i+1]>buyin: //边界条件判断
                profit += prices[i+1] - buyin
        return profit
```
