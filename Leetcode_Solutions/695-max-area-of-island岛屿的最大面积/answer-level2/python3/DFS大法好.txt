### 解题思路
DFS

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        m,n = len(grid), len(grid[0])
        max_s=0
        flag=[[False]*n for i in range(m)]
        def dfs(i, j, grid, m, n, flag):
            flag[i][j]=True
            grid[i][j]=2
            area=1
            for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                new_i=i+x
                new_j=j+y
                if 0<=new_i<m and 0<=new_j<n and grid[new_i][new_j]==1 and not flag[new_i][new_j]:
                    area+=dfs(new_i, new_j, grid, m, n, flag)
            return area

        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    max_s = max(dfs(i, j, grid, m, n,flag), max_s)
        return max_s
```