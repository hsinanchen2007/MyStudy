
首先，可以将数组中的障碍物1全改为-1，**for循环中首先判断当前是否为-1，若是，则该点的路径为0**

- 当前值为-1，则当前位置赋为0；
- 当在终点时，赋为1；
- 当到达最下，则当前的路径是由j+1的路径所决定；
- 当到达最右，当前路径由i+1的路径决定；
- 当前的所有路径情况由matrix\[i+1]\[j] + matrix\[i][j+1]决定




```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
    	m, n = len(obstacleGrid), len(obstacleGrid[0])
    	obstacleGrid = [[i*-1 for i in j] for j in obstacleGrid]
    	for i in range(m-1, -1, -1):
    		for j in range(n-1, -1, -1):
    			if obstacleGrid[i][j] == -1:
    				obstacleGrid[i][j] = 0
    			elif i == m-1 and j == n-1:
    				obstacleGrid[i][j] = 1
    			elif j == n - 1:
    				obstacleGrid[i][j] = obstacleGrid[i+1][j]
    			elif i == m - 1:
    				obstacleGrid[i][j] = obstacleGrid[i][j+1]
    			else:
    				obstacleGrid[i][j] = obstacleGrid[i+1][j]+ obstacleGrid[i][j+1]
    	return obstacleGrid[0][0]
```
