
```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        if len(grid)==0:return 0
        rows = len(grid)
        cols = len(grid[0])
        res = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]=='1':
                    res += 1
                    self.helper(grid, i, j)
        return res
    
    def helper(self, grid, i, j): #递归将每个小岛的标签更新为2
        grid[i][j] = '2'
        if i-1>=0 and grid[i-1][j]=='1':#上边
            self.helper(grid, i-1,j)
        if i+1<len(grid) and grid[i+1][j]=='1':  #下边
            self.helper(grid, i+1,j)
            
        if j-1>=0 and grid[i][j-1]=='1':  #左边
            self.helper(grid,i,j-1)
        if j+1<len(grid[0]) and grid[i][j+1]=='1':   #右边
            self.helper(grid,i,j+1)
        
```