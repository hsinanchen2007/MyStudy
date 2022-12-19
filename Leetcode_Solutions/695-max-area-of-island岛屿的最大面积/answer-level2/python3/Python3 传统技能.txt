### 解题思路

1，搜索的时候将当前的点置为 0，防止重复搜索
2，搜索这个点周围的值

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        leni = len(grid)
        if leni == 0:
            return 0
        
        lenj = len(grid[0])
        if lenj == 0:
            return 0
        
        
        self.rev = 0
        
        def dfs(grid, i, j, temp):
            if i<0 or i>=leni or j<0 or j>=lenj:
                return 0
            if grid[i][j] == 0:
                return 0
            grid[i][j] = 0
            temp = temp+1
            one = dfs(grid, i+1, j, 0)
            two = dfs(grid, i-1, j, 0)
            three = dfs(grid, i, j-1, 0)
            four = dfs(grid, i, j+1, 0)
            temp = one+two+three+four+temp
            
            self.rev = max(self.rev, temp)
            
            return temp
        
        for i in range(leni):
            for j in range(lenj):
                if grid[i][j] == 1:
                    dfs(grid, i, j, 0)
                    
        return self.rev
```