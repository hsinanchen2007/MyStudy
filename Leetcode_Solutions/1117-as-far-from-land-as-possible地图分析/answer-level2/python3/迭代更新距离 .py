- 建立新的地图 陆地位置为0 其他位置为MAX_INT
- 从左上到右下遍历更新一次
- 从右下到左上跟新遍历一次
```
class Solution:
    def maxDistance(self, grid) -> int:
        
        res = -1
        N = len(grid)
        dp = [[1000 for _ in range(N)] for _ in range(N)]

        all_zero = True
        for i in range(N):
            for j in range(N):
                if grid[i][j]==1:
                    all_zero=False
                    dp[i][j] = 0
        if all_zero: return -1

        for i in range(N):
            for j in range(N):
                if grid[i][j]==0:
                    if i > 0: dp[i][j] = min(dp[i][j], 1 + dp[i-1][j])
                    if j > 0: dp[i][j] = min(dp[i][j], 1 + dp[i][j-1])
        for i in range(N-1,-1,-1):
            for j in range(N-1,-1,-1):
                if grid[i][j]==0:
                    if i < N-1: dp[i][j] = min(dp[i][j], 1+dp[i+1][j])
                    if j < N-1: dp[i][j] = min(dp[i][j], 1+dp[i][j+1])
        
        # while True:
        #     no_change = True
        #     for i in range(N):
        #         for j in range(N):
        #             if grid[i][j]==0:
        #                 cur = 1+ min(dp[i+1][j] if i+1 < N else 1000, dp[i][j+1] if j+1 < N else 1000,\
        #                     dp[i-1][j] if i > 0 else 1000,dp[i][j-1] if j >0 else 1000)
                        
        #                 #只要地图有更新 循环就不该停止
        #                 if dp[i][j] > cur:
        #                     dp[i][j] = cur
        #                     no_change = False
        #             # print(dp)
        #     if no_change:
        #         break
        
        for i in range(N):
                for j in range(N):
                    if grid[i][j]==0:
                        res = max(res,dp[i][j])
        return res

# print(Solution().maxDistance([[1,0,0,0,0,1,0,0,0,1],[1,1,0,1,1,1,0,1,1,0],[0,1,1,0,1,0,0,1,0,0],[1,0,1,0,1,0,0,0,0,0],[0,1,0,0,0,1,1,0,1,1],[0,0,1,0,0,1,0,1,0,1],[0,0,0,1,1,1,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,1,1,0,0],[1,1,0,1,1,1,1,1,0,0]]))
```
