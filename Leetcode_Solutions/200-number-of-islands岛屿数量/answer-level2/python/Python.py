### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numIslands(self, grid):
        row=len(grid)
        if row==0:
            return 0
        col=len(grid[0])
        ans=0
        def dfs(r,c):
            grid[r][c]=0
            if r-1>=0 and grid[r-1][c]=='1':
                dfs(r-1,c)
            if c-1>=0 and grid[r][c-1]=='1':
                dfs(r,c-1)
            if r+1<row and grid[r+1][c]=='1':
                dfs(r+1,c)
            if c+1<col and grid[r][c+1]=='1':
                dfs(r,c+1)



        for r in range(row):
            for c in range(col):
                if grid[r][c]=='1':
                    dfs(r,c)
                    ans+=1


        return ans
```