### 解题思路
f(m, n) = min(f(m+1, n), f(m, n+1)) + grid[m][n]

### 代码
```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        res = {}
        m = len(grid)-1
        n = len(grid[0])-1
        res[m, n] = grid[m][n] 
        for i in range(m-1, -1, -1):
            res[i, n] = grid[i][n] + res[i+1, n]
        for j in range(n-1, -1, -1):
            res[m, j] = grid[m][j] + res[m, j+1]
        for m1 in range(m-1, -1, -1):
            for n1 in range(n-1, -1, -1):
                res[m1, n1] = min(res[m1+1, n1], res[m1, n1+1]) + grid[m1][n1]
        return res[0,0]
                
```