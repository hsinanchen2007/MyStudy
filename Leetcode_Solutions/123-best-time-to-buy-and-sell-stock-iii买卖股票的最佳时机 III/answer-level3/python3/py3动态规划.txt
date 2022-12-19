### 解题思路
思路：动态规划
本题的状态转移方程为：
dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])

本题的初始状态是：
dp[i][0][0] = 0    # 初始状态没有买股票，钱为0
dp[i][0][1] = -inf # 在没有买股票的情况下不可能拥有股票
dp[0][k][0] = 0
dp[0][k][1] = -prices[i]

### 代码
```python3
class Solution(object):
    def maxProfit(self, prices):
        if prices==[]:
            return 0
        l = len(prices)
        # 构建三维数组
        dp = []
        for i in range(l):
            ret = []
            for j in range(3):
                ret.append([None,None])
            dp.append(ret)
        # 初始化dp
        for i in range(l):
            dp[i][0][0]=0
            dp[i][0][1]=-float('inf')
        for i in range(l):
            for j in range(2,0,-1):
                # 初始化dp
                if i==0:
                    dp[i][j][0]=0
                    dp[i][j][1]=-prices[i]
                    continue
                dp[i][j][0]=max((dp[i-1][j][0],dp[i-1][j][1] + prices[i]))
                dp[i][j][1]=max((dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]))
        return dp[-1][2][0]
```