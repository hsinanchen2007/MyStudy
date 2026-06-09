### 解题思路
此处撰写解题思路
dp

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])
        rec=[1]*cols
        for i in range(cols):
            if obstacleGrid[0][i] or (i >0 and ( obstacleGrid[0][i-1] or  not rec[i-1])):
                rec[i] =0
        for row in range(1,rows):
            if obstacleGrid[row][0] == 1:
                rec[0] = 0
            for col in range(1,cols):
                if obstacleGrid[row][col] == 1:
                    rec[col] = 0
                else:
                    rec[col] += rec[col -1]
        return rec[-1]
                
                
```