第一步 构建二维动态规划表dp[i][j], 来表示猜 i~j 范围的最小代价。
第二步 假设前n个数的动态规划表已经填写好，那么数n+1，从n~n+1， n-1~n+1， n-2~n+1，..., 1 ~ n+1的方向更新。
转移方程为 dp[i][j] = min([i+k+max(dp[i][i+k-1], dp[i+k+1][j]) for k in range(1, j-i)])


    class Solution:
        def getMoneyAmount(self, n: int) -> int:
        
            dp = [[0]*(n+1) for _ in range(n+1)]
            
            for i in range(1, n):
                dp[i][i+1] = i
            
            for j in range(3, n+1):
                for i in range(j-2, 0, -1):
                    dp[i][j] = min([i+k+max(dp[i][i+k-1], dp[i+k+1][j]) for k in range(1, j-i)])
            
            return dp[1][-1]

