```
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        r,c = len(grid), len(grid[0])
        dp = [[[0,0] for j in range(c+1)] for i in range (r+1)]
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    dp[i+1][j+1][0] = 1 + dp[i+1][j][0]
                    dp[i+1][j+1][1] = 1 + dp[i][j+1][1]
        ans = 0
        for i in range(1,r+1):
            for j in range(1,c+1):
                height = min(dp[i][j])
                while height > ans:
                    if min(dp[i][j][0],dp[i][j][1],dp[i-height+1][j][0],dp[i][j-height+1][1]) >= height:
                        ans = height
                        break
                    else:
                        height -= 1
        
        return ans*ans
```
