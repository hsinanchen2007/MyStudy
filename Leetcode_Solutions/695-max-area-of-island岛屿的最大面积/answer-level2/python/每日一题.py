### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def dfs(self,grid,x,y):
        if x<0 or y<0 or x >= self.row or y >= self.col or grid[x][y]!=1:
            return 0
        grid[x][y] = 0
        tmp = 1
        for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
            tmp += self.dfs(grid,i,j)
        return tmp
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.row = len(grid)
        self.col = len(grid[0])
        ans = 0
        for i in range(self.row):
            for j in range(self.col):
                ans = max(ans,self.dfs(grid,i,j))
        return ans



```