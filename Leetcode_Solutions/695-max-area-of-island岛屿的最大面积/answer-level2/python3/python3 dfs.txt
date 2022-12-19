### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        self.maxn = 0
        
        def dfs(i,j):

            if i<0 or j<0 or i>=m or j>=n or grid[i][j]==0:
                return 0

            dir = [(0,1),(0,-1),(1,0),(-1,0)]
            grid[i][j]=0
            tmp=1
            for d in dir:
                tmp+=dfs(i+d[0],j+d[1])
            

            return tmp
            
        for i in range(m):
            for j in range(n):
                self.maxn = max(dfs(i,j),self.maxn)
        return self.maxn
```