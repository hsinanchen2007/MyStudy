### 解题思路
1. 如果入口有障碍，返回0
2. 如果不是，入口为1， 然后现将第一行和第一列的情况考虑明白
3. 然后考虑剩下的情况，最后返回数组【-1】【-1】
4. note： 请注意，不必新建数组，可在原数组上进行操作，节省空间复杂度：）

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        obstacleGrid[0][0] = 1
        for i in range(1,m):
            if obstacleGrid[i][0] == 0:
                obstacleGrid[i][0] = obstacleGrid[i-1][0]
            else:
                obstacleGrid[i][0] = 0
        for j in range(1, n):
            if obstacleGrid[0][j] == 0:
                obstacleGrid[0][j] = obstacleGrid[0][j-1]
            else:
                obstacleGrid[0][j] = 0

        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j] = 0
            
        return obstacleGrid[-1][-1]
```