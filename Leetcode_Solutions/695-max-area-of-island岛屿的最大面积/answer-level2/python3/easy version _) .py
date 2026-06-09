### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    ans = max(ans, self.update(grid, row, col))
        return ans
    
    def update(self, grid, row, col):
        if row >= 0 and row < len(grid) and col >= 0 and col < len(grid[0]) and grid[row][col]:
            grid[row][col] = 0
            return 1 + self.update(grid, row+1, col) + self.update(grid, row-1, col) + self.update(grid, row, col-1) + self.update(grid, row, col+1)
        return 0
           
```