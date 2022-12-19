### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        row_num = len(grid)
        col_num = len(grid[0])
        for row in range(1, row_num):
            grid[row][0] = grid[row - 1][0] + grid[row][0]
        for col in range(1, col_num):
            grid[0][col] = grid[0][col - 1] + grid[0][col]

        for row in range(1, row_num):
            for col in range(1, col_num):
                grid[row][col] = max(grid[row - 1][col], grid[row][col - 1]) + grid[row][col]

        return grid[row_num - 1][col_num - 1]

```