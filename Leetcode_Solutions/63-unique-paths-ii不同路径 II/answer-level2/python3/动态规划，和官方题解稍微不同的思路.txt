和官方题解稍微不一样的做法：

当前格子的状态只和上边格子和左边格子的状态有关，所以分四种情况：
1、左边和上边格子都为没有障碍：
dp[i][j] = dp[i-1][j] + dp[i][j-1]
2、左边格子有障碍，上边格子没有障碍：
dp[i][j] = dp[i][j-1]
3、左边格子没障碍，上边格子有障碍：
dp[i][j] = dp[i-1][j]
4、左边和上边格子都有障碍：
dp[i][j] = 0

但是这个思路有个问题就是要处理很多特殊情况：要提前初始化好左变列和上边行，要对只有一列和一行的情况做特殊处理....


```python []
class Solution:
    def _init_dp_table(self, obstacleGrid):
        dp = [[0 for x in obstacleGrid[0]] for y in obstacleGrid]
        
        pre_has_obstacle = False
        for i in range(1, len(obstacleGrid[0])):
            if not pre_has_obstacle and obstacleGrid[0][i] == 0:
                dp[0][i] = 1
            if obstacleGrid[0][i] == 1:
                pre_has_obstacle = True

        pre_has_obstacle = False
        for i in range(1, len(obstacleGrid)):
            if not pre_has_obstacle and obstacleGrid[i][0] == 0:
                dp[i][0] = 1
            if obstacleGrid[i][0] == 1:
                pre_has_obstacle = True
        return dp

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid[0])
        m = len(obstacleGrid)

        if obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1:
            return 0

        if n == 1:
            if [1] in obstacleGrid:
                return 0
            return 1

        if m == 1:
            if 1 in obstacleGrid[0]:
                return 0
            return 1

        dp = self._init_dp_table(obstacleGrid)

        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i - 1][j] == 0 and obstacleGrid[i][j - 1] == 0:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                elif obstacleGrid[i - 1][j] == 0:
                    dp[i][j] = dp[i - 1][j]
                elif obstacleGrid[i][j - 1] == 0:
                    dp[i][j] = dp[i][j - 1]
                print(i, j, obstacleGrid[i][j], dp[i][j])

        return dp[m - 1][n - 1]
```


