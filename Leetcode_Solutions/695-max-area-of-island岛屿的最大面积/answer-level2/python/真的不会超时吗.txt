### 解题思路
我想通了,时间复杂度是O(n^2)
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        r = len(grid)
        c = len(grid[0])
        ret=0
        vis = [[False for i in range(c)] for j in range(r)]
        def dfs(i,j):
            vis[i][j]=True
            if grid[i][j]==0:return 0
            ret = 1
            if j<c-1 and not vis[i][j+1]:
                ret+=dfs(i,j+1)
            if j>0 and not vis[i][j-1]:
                ret+=dfs(i,j-1)
            if i<r-1 and not vis[i+1][j]:
                ret+=dfs(i+1,j)
            if i>0 and not vis[i-1][j]:
                ret+=dfs(i-1,j)

            return ret

        for i in range(r):
            for j in range(c):
                if not vis[i][j]:
                    ret = max(ret,dfs(i,j))
        return ret



```