#### 定义函数判断3*3的方阵是否为幻方，然后依次判断原矩阵中的每个3*3的矩阵
```
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        if len(grid) < 3 or len(grid[0]) < 3:
            return 0
        count = 0
        row = len(grid)
        col = len(grid[0])
        for i in range(row):
            for j in range(col):
                if 0 <= i+2 <row and 0 <= j+2 < col:
                    count += self.isgrid([grid[i][j:j+3], grid[i+1][j:j+3], grid[i+2][j:j+3]])
        return count
    def isgrid(self, grid):
        new = []
        for k in grid:
            new += k
            a = set()
        new.sort()
        if new != list(range(1,10)): return 0
        # for m in new:
        #     if m not in [1,2,3,4,5,6,7,8,9]:
        #         return 0
        #     if m not in a:
        #         a.add(m)
        #     else:
        #         return 0
        c_sum = sum(grid[0])
        for row in grid:
            if sum(row) != c_sum:
                return 0
        for col in range(len(grid[0])):
            if grid[0][col] + grid[1][col] + grid[2][col] != c_sum:
                return 0
        if grid[0][0] + grid[1][1] + grid[2][2] != c_sum:
            return 0
        if grid[0][2] + grid[1][1] + grid[2][0] != c_sum:
            return 0
        return 1

```
