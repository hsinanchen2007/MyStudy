- 建立一个新图dp，dp[i][j]表示相应位置离陆地的距离
- 陆地位置 初始化为0  其他位置初始化为最大值10000
- 循环遍历地图，一次更新每个位置的最小值 1+min(dp[i-1][j],dp[i+1][j],dp[i][j+1],dp[i][j-1])
- 直到任何位置无任何变化  停止更新 的最大值
```
class Solution:
    def maxDistance(self, grid) -> int:
        
        res = -1
        N = len(grid)
        dp = [[1000 for _ in range(N)] for _ in range(N)]
        # def dis(m,n):
        #     if (m,n) in self.memo:
        #         return self.memo[(m,n)]
        #     if m <0 or m>=N or n<0 or n>=N or grid[m][n]==1:
        #         return 0
        #     self.memo[(m,n)] = 1 +min([dis(m-1,n),dis(m,n-1),dis(m,n+1),dis(m+1,n)])
        #     return self.memo[(m,n)]
        all_zero = True
        for i in range(N):
            for j in range(N):
                if grid[i][j]==1:
                    all_zero=False
                    dp[i][j] = 0
        if all_zero: return -1
        while True:
            no_change = True
            for i in range(N):
                for j in range(N):
                    if grid[i][j]==0:
                        cur = 1+ min(dp[i+1][j] if i+1 < N else 1000, dp[i][j+1] if j+1 < N else 1000,\
                            dp[i-1][j] if i > 0 else 1000,dp[i][j-1] if j >0 else 1000)
                        
                        #只要地图有更新 循环就不该停止
                        if dp[i][j] > cur:
                            dp[i][j] = cur
                            no_change = False
                    # print(dp)
            if no_change:
                break
        
        for i in range(N):
                for j in range(N):
                    if grid[i][j]==0:
                        res = max(res,dp[i][j])
        return res

# print(Solution().maxDistance([[1,0,0,0,0,1,0,0,0,1],[1,1,0,1,1,1,0,1,1,0],[0,1,1,0,1,0,0,1,0,0],[1,0,1,0,1,0,0,0,0,0],[0,1,0,0,0,1,1,0,1,1],[0,0,1,0,0,1,0,1,0,1],[0,0,0,1,1,1,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,1,1,0,0],[1,1,0,1,1,1,1,1,0,0]]))
```
