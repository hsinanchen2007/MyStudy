### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if obstacleGrid[m-1][n-1] == 1 or obstacleGrid[0][0] == 1:
            return 0
        dp = [[0]* n for i in range(m)]
        
        dp[0][0] =1
        for i in range(1,m):
            if obstacleGrid[i][0]==1:
                break
            dp[i][0]=1

        for j in range(1,n):
            if obstacleGrid[0][j]==1:
                break;
            dp[0][j] = 1

        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i-1][j] == 0 and obstacleGrid[i][j-1] == 0:
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]
                elif obstacleGrid[i-1][j] == 0:
                    dp[i][j] = dp[i-1][j]
                elif obstacleGrid[i][j-1] == 0:
                    dp[i][j] = dp[i][j-1]
                else:
                    dp[i][j] = 0

        return dp[m-1][n-1]
                    
```