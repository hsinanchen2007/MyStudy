### 解题思路
套路化的动态规划


### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        #dp表还是那个
        n=len(obstacleGrid)
        m=len(obstacleGrid[0])
        dp=[[0]*m for _ in range(n)]
        print(dp[0])
        if obstacleGrid[0][0]==1:
            return 0
        #初始条件
        dp[0][0]=1
        for i in range(1,n):
            if obstacleGrid[i][0]==1:
                break
            else:
                dp[i][0]=1
        for i in range(1,m):
            if obstacleGrid[0][i]==1:
                break
            else:
                dp[0][i]=1
            

        #转移方程
        for i in range(1,n):
            for j in range(1,m):
                if obstacleGrid[i][j]==0:
                    dp[i][j]=dp[i-1][j]*abs(obstacleGrid[i-1][j]-1)+dp[i][j-1]*abs(obstacleGrid[i][j-1]-1)
                else:
                    dp[i][j]=0
        print(dp[0])
        return dp[n-1][m-1]
        

```