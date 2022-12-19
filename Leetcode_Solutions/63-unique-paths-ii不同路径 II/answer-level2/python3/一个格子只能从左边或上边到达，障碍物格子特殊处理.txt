动态规划。将到达格子 [i, j] 的路径数记为 `dp[i][j]`，因为一个格子只能从它上边或左边的格子到达，所以有：

```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
```

当某个格子存在障碍物时，这个格子是无法到达的，因此 `dp[i][j] = 0`。

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # m * n 矩阵
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        
        # 第一个格子或最后一个格子有障碍物，直接返回 0
        if obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1:
            return 0
        
        dp = [[0 for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                
                # 第一步特殊处理
                if i == 0 and j == 0:
                    dp[0][0] = 1
                    continue
                
                # 有障碍物则走不到这个格子
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    if i > 0 and j > 0:
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                    else:
                        if i == 0:
                            dp[i][j] = dp[i][j - 1]
                        if j == 0:
                            dp[i][j] = dp[i - 1][j]
                            
        return dp[m - 1][n - 1]
```

### 复杂度

- 时间复杂度：`O(m * n)`
- 空间复杂度：我这里初始化了一个 `dp`，所以空间复杂度为 `O(m * n)`。也可以直接使用原数组 `obstacleGrid`，这样空间复杂度就是 `O(1)`。