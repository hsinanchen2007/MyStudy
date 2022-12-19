### 解题思路


### 代码

```python
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        for i in range(n):
            if obstacleGrid[0][i] == 0:
                obstacleGrid[0][i] = 1
            else:
                obstacleGrid[0][i] = 0
                break
        for j in range(i+1,n):
            obstacleGrid[0][j] = 0
        for i in range(1,m):
            if obstacleGrid[i][0] == 0:
                obstacleGrid[i][0] = 1
            else:
                obstacleGrid[i][0] = 0
                break
        for j in range(i+1,m):
            obstacleGrid[j][0] = 0
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                    continue
                else:
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]
        return obstacleGrid[-1][-1]
      
```