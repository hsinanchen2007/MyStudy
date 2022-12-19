### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        dp = [[0 for _ in range(col)] for _ in range(row)]
        if obstacleGrid[-1][-1]==1:
            return 0
        if obstacleGrid[0][0]==1:
            return 0
        dp[0][0]=1
        for i in range(1,row):
            if obstacleGrid[i][0]==1:
                for j in range(1,row):
                    dp[i][0]=0
                break
            else:
                dp[i][0]=1
        for i in range(1,col):
            if obstacleGrid[0][i]==1:
                for j in range(1,col):
                    dp[0][i]=0
                break
            else:
                dp[0][i]=1
        for i in range(1,row):
            for j in range(1,col):
                if obstacleGrid[i][j]==1:
                    dp[i][j]=0
                else:
                    dp[i][j]=dp[i][j-1]+dp[i-1][j]
        return dp[-1][-1]
        
```