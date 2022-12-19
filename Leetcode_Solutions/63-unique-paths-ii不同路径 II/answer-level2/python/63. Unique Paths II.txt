`if obstacleGrids[i][j] == 0:
  obstacleGrids[i][j] = obstacleGrids[i-1][j] + obstacleGrids[i][j]`

```
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if obstacleGrid[0][0] == 1: return 0

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        grid = [[0 for _ in range(n)] for _ in range(m)]
        grid[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                else:
                    if obstacleGrid[i][j] != 1:
                        if i == 0 and j > 0:
                          grid[i][j] += grid[i][j - 1]
                        elif i > 0 and j == 0:
                            grid[i][j] += grid[i - 1][j]
                        else:
                            grid[i][j] = grid[i][j - 1] + grid[i - 1][j]
        return grid[-1][-1]
```
