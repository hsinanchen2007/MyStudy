基本思路是DFS，用zero_cnt记录走过多少个0，用visited二维数据记录每个位置是否已经被访问过。
从起始结点(start[0], start[1])开始深度优先搜索，某个点(x, y)访问过后，将其设为已经访问(visited[x][y] = True)，且zero_cnt += 1；深度搜索结束之后，把该位置设为未访问visited[x][y] = False，同时zero_cnt -= 1。
如果访问到值为2的位置且zero_cnt数量达到要求，则在返回结果上+1。

```python3
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start, zero = None, 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    zero += 1
                elif grid[i][j] == 1:
                    start = i, j
        visited = [[False for j in range(n)] for i in range(m)]
        zero_cnt = 0
        visited[start[0]][start[1]] = True
        return self.dfs(grid, start[0], start[1], m, n, visited, zero_cnt,
                        zero)

    def dfs(self, grid, i, j, m, n, visited, zero_cnt, zero):
        total = 0
        for x, y in self.neighbor(i, j, m, n):
            if grid[x][y] == 0 and visited[x][y] == False:
                visited[x][y] = True
                zero_cnt += 1
                total += self.dfs(grid, x, y, m, n, visited, zero_cnt, zero)
                visited[x][y] = False
                zero_cnt -= 1
            elif grid[x][y] == 2 and zero_cnt == zero:
                total += 1
        return total

    def neighbor(self, i, j, m, n):
        if i > 0:
            yield i - 1, j
        if j > 0:
            yield i, j - 1
        if i + 1 < m:
            yield i + 1, j
        if j + 1 < n:
            yield i, j + 1
```
