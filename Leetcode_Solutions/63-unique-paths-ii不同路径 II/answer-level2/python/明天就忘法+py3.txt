### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        #行
        m=len(obstacleGrid)
        #列
        n=len(obstacleGrid[0])
        dp=[[0]*n for _ in range(m)]
        # 在第一行 第一列 遇到1 则赋值为0 然后终止 如果都没有1 则赋值为1
        for i in range(m):
            if obstacleGrid[i][0]==1:
                dp[i][0]=0
                break
            else:
                dp[i][0]=1
      
        for j in range(n):
            if obstacleGrid[0][j]==1:
                dp[0][j]=0
                break
            else:
                dp[0][j]=1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j]==1:
                    dp[i][j]=0
                else:
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]
```