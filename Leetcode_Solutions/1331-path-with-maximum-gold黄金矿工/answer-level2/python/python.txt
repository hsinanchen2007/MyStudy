### 解题思路
直接贴代码了

### 代码

```python
class Solution(object):

    def dfs(self, x, y, step, steps, golds):
        result = [golds, ]
        steps[(x, y)] = step
        for (xdt, ydt) in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            curx, cury = x + xdt, y + ydt
            if (curx, cury) in steps or not(0<=curx<self.n) or not (0<=cury<self.m):
                continue

            if not self.grid[curx][cury]:
                continue
            result.append(
                self.dfs(curx, cury, step+1, steps, golds + self.grid[curx][cury])
            )
        steps.pop((x, y))

        return max(result)

    def can_be_start(self, x, y):
        contact = 0
        for (xdt, ydt) in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            curx, cury = x + xdt, y + ydt
            if not(0<=curx<self.n) or not (0<=cury<self.m):
                continue

            if self.grid[curx][cury]:
                contact += 1

        return contact < 2

    def getMaximumGold(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.n = len(grid)
        self.m = len(grid[0])
        self.grid = grid

        ans = 0
        curx = cury = -1
        for x in range(self.n):
            for y in range(self.m):
                if not grid[x][y]:
                    continue

                if not self.can_be_start(x, y):
                    curx, cury = x, y
                    continue
                ans = max(ans, self.dfs(x, y, 0, {}, grid[x][y]))

        if not ans and curx != -1:
            ans = self.dfs(curx, cury, 0, {}, grid[curx][cury])

        return ans
```