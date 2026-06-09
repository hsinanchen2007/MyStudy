### 解题思路
深度优先搜索，搜索矩阵中1的块数，块是指由1个或多个1连在一起
第一步，用visited矩阵记录每个位置是否被访问过
第二步，对没有访问过的1进行深度优先搜索，所有能访问到的1都是连在一起的
第三步，计算res，如果一个1没有被访问过，那么从新开始深搜，res += 1
### 代码

```python
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        res = 0
        if grid:
            m = len(grid)
            n = len(grid[0])

            visited = [[False for j in range(n)] for i in range(m)]

            def dfs(i, j):
                for k, l in ((-1, 0), (0, -1), (1, 0), (0, 1)):
                    if 0 <= i + k < m and 0 <= j + l < n and grid[i + k][j + l] == '1' and not visited[i + k][j + l]:
                        visited[i + k][j + l] = True
                        dfs(i + k, j + l)

            for i in range(m):
                for j in range(n):
                    if not visited[i][j] and grid[i][j] == '1':
                        res += 1
                        visited[i][j] = True
                        dfs(i, j)

        return res
```