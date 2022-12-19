```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n=len(prices)
        res=0
        tmp=0
        for i in range(0,n-1):
            # 找到一个谷底
            if prices[i]<prices[i+1]:
                # 更新最低的谷底
                if prices[i]<prices[tmp]:
                    tmp=i
            else:
                # 找到谷峰 计算差值
                money=prices[i]-prices[tmp]
                # 更新最大利润
                res=max(money,res)
            # 最后一段全是递增的价格 计算这段可能的利润
            # tmp是当前的最低买入价格的下标
            # n-1是谷峰（最后一天）
            if i==n-2:
                res=max(res,prices[n-1]-prices[tmp])
        return res

```
