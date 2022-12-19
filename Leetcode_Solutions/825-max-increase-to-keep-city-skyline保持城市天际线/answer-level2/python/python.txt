### 解题思路
遍历1，找出行最大
遍历2，找出列最大
遍历3，计算最大填充

### 代码

```python3
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        if not grid: return 0
        n, m = len(grid), len(grid[0])
        row_max, col_max = [], []
        for r in range(n):
            row_max.append(max(grid[r]))
        for c in range(m):
            col_max.append(max([grid[r][c] for r in range(n)]))
        total = 0
        for r in range(n):
            for c in range(m):
                total += min(row_max[r], col_max[c]) - grid[r][c]
        return total

```