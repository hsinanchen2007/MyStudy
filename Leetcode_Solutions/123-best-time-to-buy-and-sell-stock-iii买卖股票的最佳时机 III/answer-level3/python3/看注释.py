```
class Solution:
    def maxProfit(self, prices) -> int:
        l=len(prices)
        if l<2:
            return 0
        res=0
        #先算一个dp1数组
        #dp1[i]表示截止到第i-1天只进行一次买卖的最大利润
        dp1=[0 for i in range(l)]
        max_price,min_price=prices[0],prices[0]
        for i in range(1,l):
            dp1[i]=max(dp1[i-1],prices[i]-min_price)
            #对于第i天来说，1.如果当天卖：最大利润即当前卖出价格
            #减去之前的最小买入价格，2如果不卖：最大利润和前一天的
            #最大利润相同
            min_price=min(min_price,prices[i])  #更新当前最小买入价格
            max_price=max(max_price,prices[i])  #更新当前最大卖出价格
        #对于任意k，dp1[k]表示k卖出的最大利润，
        #那么需要求剩下k+1到n-1的最大利润
        #倒着求，因为右边界不变始终为l-1，左边界在变化
        #dp2[i]表示从i开始到最后只进行一次买卖的最大利润
        res=dp1[-1]
        # print(res)
        dp2=[0 for i in range(l)]
        max_price=prices[-1]
        for i in range(l-2,-1,-1):
            dp2[i]=max(dp2[i+1],max_price-prices[i])
            #对于第i天，1.若当天买，则最大利润即之后的最大卖出价格减去
            #当前买入价格，2.若当天不买，最大利润和后一天的最大利润相同
            max_price=max(max_price,prices[i])  #更新当前最大卖出价格
            res=max(res,dp1[i-1]+dp2[i]) if i>=1 else max(res,dp2[i])
        # print(dp1)
        # print(dp2)
        return res
```
