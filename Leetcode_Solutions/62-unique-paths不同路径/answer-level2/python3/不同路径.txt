```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mem = [[0]*m for _ in range(n)]
        return self._uniquePaths(m, n, 0, 0, mem)

    def _uniquePaths(self, m, n, row, col, mem):
        if row == n - 1 or col == m - 1:
            return 1

        if row < n and col < m and mem[row][col] != 0:
            return mem[row][col]

        mem[row][col] = self._uniquePaths(m, n, row + 1, col, mem) +\
                         self._uniquePaths(m, n, row, col + 1, mem)
        return mem[row][col]

```