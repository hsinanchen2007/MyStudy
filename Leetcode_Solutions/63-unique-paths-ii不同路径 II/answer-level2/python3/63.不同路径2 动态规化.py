
### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid) # 行数
        m = len(obstacleGrid[0]) # 列数
        dp = [[0 for _ in range(m)] for _ in range(n)]
        # print(dp)
        # 初始化第一行和第一列：
        # 对于第一列和第一行来说，前一个是障碍物的话，就一定不能到达这一点
        for i in range(0,m):
            ## 对行初始化
            if obstacleGrid[0][i] != 1:
                dp[0][i] = 1
            else: break
        for i in range(0, n):
            if obstacleGrid[i][0] != 1:
                dp[i][0] = 1
            else: break
        print(dp)
        # 开始对其他位置的dp 进行操作：
        for i in range(1,n):
            for j in range(1,m):
                # 先判断这个点是否为障碍物
                if obstacleGrid[i][j] ==1: dp[i][j] =0
                ## 再判断这个点左上是否都为障碍物
                elif obstacleGrid[i][j-1] == 1 and obstacleGrid[i-1][j] ==1:
                    dp[i][j] = 0
                ## 再判断这个点的左边是否为障碍物
               
                elif obstacleGrid[i][j-1] == 1:
                    dp[i][j] = dp[i-1][j]
                 ## 判断这个点右边是否为障碍物
                
                elif obstacleGrid[i-1][j] == 1:
                    dp[i][j] = dp[i][j-1]
                ## 如果自己，左边，右边 都不是障碍物
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[-1][-1]
```