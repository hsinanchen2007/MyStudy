### 解题思路动态规划

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if grid==[] or grid==[[]]:
            return 0
        m = len(grid)
        n = len(grid[0])
        #dp = [[0]*n for _ in range(m)] 直接在原数组上面修改即可，节省内存空间
        if m==1:
            return grid[0][n-1]
        if n==1:
            return grid[m-1][0]
            
        for i in range(1,n):
            grid[0][i] = grid[0][i-1]+grid[0][i]
        for j in range(1,m):
            grid[j][0] = grid[j-1][0]+grid[j][0]

        for i in range(1,m):
            for j in range(1,n):
               grid[i][j] = max(grid[i-1][j]+grid[i][j],grid[i][j-1]+grid[i][j]) 
        return grid[m-1][n-1]
```