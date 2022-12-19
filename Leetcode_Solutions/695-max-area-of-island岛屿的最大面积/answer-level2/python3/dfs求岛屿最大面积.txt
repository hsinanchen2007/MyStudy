### 解题思路
每次遍历过的点把其值置为0，下次就不会再统计。

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        directions=[(1,0),(-1,0),(0,1),(0,-1)]
        def dfs(i,j):
            if i<0 or j<0 or i>=m or j>=n or grid[i][j]==0:
                return 0
            grid[i][j]=0
            res=1
            for x,y in directions:
                res+=dfs(i+x,j+y)
            return res

        res=0
        for i in range(m):
            for j in range(n):
                res=max(res,dfs(i,j))
        return res
```