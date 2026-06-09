dp[i][j] 表示前i天，最多执行j次交易获得最大利益。
case 1:
    第i天什么不做，那么就等于dp[i-1][j]
        dp[i][j] = dp[i-1][j]
case 2:
    第i天卖出的话，那么:
        MaxVal = max(prices[i] + dp[k][j-1] - prices[k],MaxVal) // k = 1,2,..i-1
dp[i][j] = max(dp[i-1][j],MaxVal)
            
        改进:
            第二种情况每次从前找dp[k][j-1] - arr[k](k = 1,2,..,i-1)的最大值,可以记录之前的dp[k][j-1] - arr[k]的最大值。
            例 tempVal[i][j]用来记录，具体含义：前i天，最多执行j次交易的dp[k][j] - prices[k](k=1,2,..i)最大值。
                那么递推式有：
                    1.
                        dp[i][j] = max(dp[i-1][j],tempVal[i-1][j-1] + prices[i])
                    2.
                        tempVal[i][j-1] = max(temp[i-1][j-1],dp[i][j-1] - prices[i])
                        由递推式易知，temp第一维其实可以去掉，每次更新时，会自动记录之前的最值。

代码如下:
```
class Solution:
    def maxProfit(self, prices):
        l = len(prices)
        dp = [[0]*3 for _ in range(l+1)]
        
        tempVal = [-1000000]*3
        for i in range(1,l+1):
            for j in range(1,3):
                dp[i][j] = max(dp[i-1][j],prices[i-1] + tempVal[j-1])
                tempVal[j-1] = max(tempVal[j-1],dp[i][j-1] - prices[i-1])

#         for i in dp:
#             print(i)
        return dp[-1][-1]
```
