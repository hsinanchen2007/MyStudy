一个通用方法团灭 6 道股票问题 中的这道题解法没看懂，我的内层循环为交易次数，从0一直到maxk
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #判空
        if not prices:
            return 0

        #初始化状态
        maxk = 2  #最大可执行的交易次数
        dp = [[[0,0]for i in range(3)]for i in range(len(prices))]
        for k in range(maxk+1):
            #第1天，卖出k次，当前状态未持股/持股
            dp[0][k][0] = 0
            dp[0][k][1] = -prices[0]

        #状态转移
        #外层循环天数
        for i in range(1,len(prices)):
            #内层循环交易次数
            for k in range(maxk+1):  
                if k == 0: #如果交易次数为0，当天最大收益等去昨天最大收益
                    dp[i][k][0] = dp[i][k-1][0]
                else: #如果不为零，继续
                    dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
                dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
        return max(dp[len(prices)-1][0][0],dp[len(prices)-1][1][0],dp[len(prices)-1][2][0])
```
