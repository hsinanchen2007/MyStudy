### 解题思路
与上一题相比，这一题不同之处在于初始条件。

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]==1 or obstacleGrid[-1][-1]==1:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp=[[0]*n for _ in range(m)]
        # 初始化第一行与第一列，有障碍物后面的都设置为0
        flag=False
        for i in range(m):
            if flag:
                dp[i][0]=0
            else:
                if obstacleGrid[i][0]==1:
                    dp[i][0]=0
                    flag=True
                else:
                    dp[i][0]=1
        flag=False
        for j in range(n):
            if flag:
                dp[0][j]=0
            else:
                if obstacleGrid[0][j]==1:
                    dp[0][j]=0
                    flag=True
                else:
                    dp[0][j]=1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j]==1:
                    dp[i][j]=0
                    continue
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[-1][-1]
```