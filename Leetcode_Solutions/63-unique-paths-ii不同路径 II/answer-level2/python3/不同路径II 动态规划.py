### 解题思路
其实就是在62题的基础上加上了对第一行和第一列格子状态的判断
以及在对转移状态方程每个状态赋值之前判断是否有障碍

### 代码

```python3
class Solution:
    # 和无障碍物类似
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # 行数和列数
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        # 初始化
        dp = [[1]*n for _ in range(m)]

        # 检查第一行 and 第一列时，只要出现1，则该格子与其下面/右面所有格子都变成0
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                for t in range(i, m):
                    dp[t][0] = 0
                break

        for j in range(n):
            if obstacleGrid[0][j] == 1:
                for t in range(j, n):
                    dp[0][t] = 0
                break

        for i in range(1, m):
            for j in range(1, n):
                # 有障碍物
                if obstacleGrid[i][j] == 1: 
                    dp[i][j] = 0
                    continue
                
                # 如果循环从0开始，以下会出错，因此需要先对第一行和第一列做处理
                dp[i][j] = dp[i-1][j] +dp[i][j-1]
        
        return dp[m-1][n-1]
```