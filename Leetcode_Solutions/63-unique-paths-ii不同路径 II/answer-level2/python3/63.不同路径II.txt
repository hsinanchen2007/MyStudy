### 解题思路
摔死在深复制浅复制上
请这么赋值：
dp = [[0 for i in range(n)] for i in range(m)]
错误初始化：
dp = m*[n*[0]]

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m,n = len(obstacleGrid),len(obstacleGrid[0])
        '''
        初始化第一行和第一列，障碍物后面都不可达
        填充dp数组，分三种情况：
        上边的点和左边的点都不可达，那么当前点不可达:dp[i][j] = 0
        当前点是障碍物，那么当前点不可达:dp[i][j] = 0
        上边的点或者左边的点可达，那么当前点就可达，路径数等于到上边点的路径数加到左边点的路径数:dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        '''

        dp = [[0 for i in range(n)] for i in range(m)]

        # 初始化第一行和第一列，障碍物后面都不可达
        if obstacleGrid[0][0] == 1:
            return 0

        dp[0][0] = 1

        # 第一列的元素填充
        for i in range(m):
            dp[i][0] = 1
            if obstacleGrid[i][0] == 1:
                for j in range(i):
                    dp[j][0] = 1
                for j in range(i,m):
                    dp[j][0] = 0
                break
        
        # 第一行的元素填充
        for i in range(n):
            dp[0][i] = 1
            if obstacleGrid[0][i] == 1:
                for j in range(i):
                    dp[0][j] = 1
                for j in range(i,n):
                    dp[0][j] = 0
                break

        for i in range(1,m):
            for j in range(1,n):
                #如果上方和左方不可达 或者 本身有障碍物 则不可达
                if obstacleGrid[i][j] == 1 or (obstacleGrid[i-1][j] and obstacleGrid[i][j-1]):
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                    
        return dp[m-1][n-1]
```