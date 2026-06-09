```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        grid=[[0]*len(obstacleGrid[0]) for _ in range(len(obstacleGrid))]
        grid[0][0]=1
        for y in range(len(obstacleGrid)):
            for x in range(len(obstacleGrid[0])):
                if y==0 and x==0:
                    continue
                a=grid[y][x-1] if x-1>=0 and obstacleGrid[y][x-1]!=1 else 0
                b=grid[y-1][x] if y-1>=0 and obstacleGrid[y-1][x]!=1 else 0
                grid[y][x]=a+b
        return grid[-1][-1] if not obstacleGrid[-1][-1] else 0
```
