### 解题思路
学习，学习
理解，理解
财布，财布
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n, m, res = len(grid),len(grid[0]),0
        def dfs(x, y):
            if x<0 or y<0 or x==n or y==m or grid[x][y]!=1:return 0
            grid[x][y] = 0 #visited
            return dfs(x-1,y) + dfs(x+1,y) + dfs(x,y-1) + dfs(x,y+1) + 1
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:res = max(dfs(i,j), res)
        return res

```