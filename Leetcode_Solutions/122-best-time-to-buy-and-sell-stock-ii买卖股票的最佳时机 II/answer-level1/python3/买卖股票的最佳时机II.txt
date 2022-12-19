dp[i] = k 表示前i天买卖同一支股票所获得利益最大为k。
那么在第i天可以不买卖股票，也可以股票买卖。
dp[i] = max(dp[k]+ prices[i]- prices[k]),k = (1,2,...i-1)
注意上述递推式子会出现重合情况。
例：prices = [1,2,5]
则根据递推式子则有:
    dp[1] = 0
    dp[2] = 1
    dp[3] = dp[2] + 5 - 2 = 4
    这里进行两次交易。
    1. 第一天买入，第二天卖出 -> dp[2] = 1
    2. 第二天买入，第二天卖出 -> dp[3] = 4
    但是第二天同时买入和卖出，所以等价于第二天任何事情都没做。
    如何优化：
        确定dp[i]时，每次从前面查找dp[k] + prices[i] - prices[k](变 + 常量 - 变)         ，不妨将前面的dp[k]-prices[k]最大值给记录下来，则省去每次重复找前面最优解的时间。
                
        确定好优化策略之后，现给出具体步骤。
        dp[i][0] = k 表示前i天买卖同一支股票所获得利益最大为k。
        dp[i][1] = m 表示前i天dp[k]-prices[k]最大值(k =1,2,3,...,i)
        那么递推式子：
            dp[i][0] = max(dp[i-1][0],prices[i] + dp[i-1][1])
            dp[i][1] = max(dp[i][0]-prices[i],dp[i-1][1])
            最终解：dp[-1][0]
        再优化:
            若 prices = [1,2,3,4,5,6],显然maxProfit = 5
            利用贪心的思想，即有利益则获取。
            第1天时，maxProfit = 0
            第2天时，maxProfit = 1
            第3天时，maxProfit = (3-2)+(2-1) = 3-1 = 2
            第4天时，maxProfit = (4-3)+maxProfit = 3
            第7天时，maxProfit = (6-5)+maxProfit = 5 实质上第7天卖出，第1天买入。

```
class Solution:
    def maxProfit(self, prices: [int]):
        # 解法1，动态规划法
        l = len(prices)
        if l <= 1:
            return 0
                dp = [[0,0] for _ in range(l+1)]
        # 初始化
        dp[2][0] = max(prices[1] - prices[0],0) #保证利益>=0
        dp[2][1] = dp[2][0] - prices[1]
        for i in range(3,l+1):
            dp[i][0] = max(dp[i-1][0],prices[i-1]+dp[i-1][1])
            dp[i][1] = max(dp[i-1][1],dp[i][0]-prices[i-1])
#         for i in dp:
#             print(i)
        return max(dp[-1][0],0)
    def maxProfit2(self, prices: [int]):
        # 解法2贪心法
        l = len(prices)
        if l <= 1:
            return 0
        maxProfit = 0
        for i in range(1,l):
            maxProfit = max(0,prices[i] - prices[i-1])
        return maxProfit
```
