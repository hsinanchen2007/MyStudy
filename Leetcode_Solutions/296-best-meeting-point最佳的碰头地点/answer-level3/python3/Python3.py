```
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        rows, cols = [], []
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    rows.append(i)
        for j in range(col):
            for i in range(row):
                if grid[i][j] == 1:
                    cols.append(j)
        row_mid = rows[len(rows) // 2]
        col_mid = cols[len(cols) // 2]
        return sum([abs(r - row_mid) for r in rows]) + sum([abs(c - col_mid) for c in cols])
```
