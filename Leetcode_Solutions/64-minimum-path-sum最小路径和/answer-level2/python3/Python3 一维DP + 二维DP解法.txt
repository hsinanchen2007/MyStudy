```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        dp = [0] * n #一维dp
        for i in range(m):
            for j in range(n):
                if j == 0:
                    dp[j] = dp[j]
                elif i == 0:
                    dp[j] = dp[j - 1]
                else:
                    dp[j] = min(dp[j], dp[j - 1])
                dp[j] += grid[i][j]
        return dp[n - 1]
```
```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row = len(grid)
        column = len(grid[0])
        dp = [[0 for _ in range(column)] for p in range(row)] #二维动态规划
        #print(dp)
        for i in range(column):
            dp[0][i] = dp[0][i-1] + grid[0][i]
            #print(dp)
        for i in range(1, row):
            dp[i][0] = dp[i-1][0] + grid[i][0]
            for j in range(1, column):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[row-1][column-1]
```
