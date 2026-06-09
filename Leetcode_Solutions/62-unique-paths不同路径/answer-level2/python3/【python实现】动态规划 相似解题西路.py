解题思路：
根据题意可知，如果用暴力搜索，那么计算量非常大，可以考虑逆推，即从终点往起点推导。因此考虑动态规划
一、最优子结构
1. 假设之前的所有位置的情况都已知，求dp[m-1][n-1]
则可以定义dp[m-1][n-1]：该位置的路线数量
则dp[m-1][n-1]会等于其左边一个和上边一个位置的数量之和，即
dp[m-1][n-1] = dp[m-1][n-2] + dp[m-2][n-1]

二、重叠子问题
1. 根据上述递推方程，易得存在重叠的子问题。
因此可以用动态规划来解决。

时间复杂度：O(n^2)
![1.png](https://pic.leetcode-cn.com/cf1a2e51bc21a2b904650c4c7d47fe601b39a00af0af6fe47dc563979ba17eab-1.png)

```
class Solution:
    def uniquePaths(self, m, n):
        # 特殊情况
        if m <= 1:
            return m
        elif n <= 1:
            return n
        # 定义dp：二维列表，dp[i][j]表示从原点到位置(i, j)的路径数量
        dp = [[0 for _ in range(n)] for _ in range(m)]  # m * n
        
        # 自底向上填表
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = 1
                else:  # 递推方程
                    if i > 0:
                    	dp[i][j] += dp[i-1][j]
                    if j > 0:
                        dp[i][j] += dp[i][j-1]
        
        # 返回
        return dp[m-1][n-1]
```