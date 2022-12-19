```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        # queue - all starting cells with rotting oranges
        queue = collections.deque()
        for r, row in enumerate(grid): # 用了enumerate小技巧
            for c, val in enumerate(row):
                if val == 1:
                    queue.append((r, c, 0))

        def neighbors(r, c):
            for nr, nc in ((r-1,c),(r,c-1),(r+1,c),(r,c+1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc # 生成器是亮点

        d = 0
        maxd = -1
        while queue:
            r, c, d = queue.popleft()
            for nr, nc in neighbors(r, c):
                if grid[nr][nc] == 0:
                    grid[nr][nc] = 1
                    queue.append((nr, nc, d+1))
                    maxd = max(maxd, d+1)

        # if any(1 in row for row in grid): # any关键字也让代码clean不少
            # return -1
        return maxd
```