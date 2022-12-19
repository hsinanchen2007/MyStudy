
```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n=len(obstacleGrid[0])
        a= [0,1] + [0]*(n-1)
        for i in range(1,m+1):
            for j in range(1,n+1):
                if obstacleGrid[i-1][j-1]==1:
                    a[j] = 0 
                    continue
                a[j] += a[j-1]

        return a[-1]
```