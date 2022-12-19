### 解题思路
通过调用update函数，上下左右进行深度搜索，每每经过‘1’时，变为‘0’。最后得到岛屿的总数返回即可。

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for w in range(len(grid[i])):
                if grid[i][w] == '1':
                    self.update(grid, i, w)
                    ans = ans + 1 
        return ans
        
    def update(self, grid, row, col):
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]) or grid[row][col] == '0':
            return 
        else:
            grid[row][col] = '0'
            
            self.update(grid, row+1, col) 
            self.update(grid, row-1, col) 
            self.update(grid, row, col+1) 
            self.update(grid, row, col-1)

```