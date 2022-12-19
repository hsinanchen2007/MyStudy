### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        ans = [[-1]*len(grid[0]) for _ in range(len(grid))]
        def recur(grid,i,j):
            if i == len(grid) or j == len(grid[0]): return float("inf")
            if i == (len(grid)-1) and j == (len(grid[0])-1): return grid[-1][-1]
            if ans[i][j]==-1:
                ans[i][j] = grid[i][j] + min(recur(grid,i+1,j),recur(grid,i,j+1))
            return ans[i][j]
        return recur(grid,0,0)
```