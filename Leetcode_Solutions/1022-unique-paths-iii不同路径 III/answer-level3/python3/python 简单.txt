### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def helper(x, y, curstep):
            if not (0 <= x < n and 0 <= y < m and
                grid[x][y] in (0, 1, 2)
              ):
                return

            if (x, y) == end:
                self.ans += (curstep == cnt)
                return

            grid[x][y] = -2
            helper(x, y + 1, curstep + 1)
            helper(x, y - 1, curstep + 1)
            helper(x + 1, y, curstep + 1)
            helper(x - 1, y, curstep + 1)
            grid[x][y] = 0

        if not grid:
            return 0

        n, m = len(grid), len(grid[0])
        cnt = 1
        for x in xrange(n):
            for y in xrange(m):
                if grid[x][y] == 1:
                    stx, sty = x, y
                elif grid[x][y] == 0:
                    cnt += 1
                elif grid[x][y] == 2:
                    end = x, y

        self.ans = 0
        helper(stx, sty, 0)

        return self.ans
```