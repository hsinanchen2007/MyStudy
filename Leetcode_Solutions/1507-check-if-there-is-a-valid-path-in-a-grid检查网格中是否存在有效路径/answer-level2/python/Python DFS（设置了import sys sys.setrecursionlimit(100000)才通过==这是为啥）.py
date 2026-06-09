```
import sys
sys.setrecursionlimit(100000)

class Solution(object):
    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m = len(grid)
        n = len(grid[0])

        vis = [[0] * n for _ in range(m)]
        dire = [
                [(0, -1), (0, 1)],
                [(-1, 0), (1, 0)],
                [(0, -1), (1, 0)],
                [(0, 1), (1, 0)],
                [(0, -1), (-1, 0)],
                [(0, 1), (-1, 0)]
                ]
        next_dire = [
                [(1, 4, 6), (1, 3, 5)],
                [(2, 3, 4), (2, 5, 6)],
                [(1, 4, 6), (2, 5, 6)],
                [(1, 3, 5), (2, 5, 6)],
                [(1, 4, 6), (2, 3, 4)],
                [(1, 3, 5), (2, 3, 4)]
                ]
        
        def dfs(i, j):
            vis[i][j] = 1
            if (i == m - 1 and j == n - 1): return True
            flag = False
            for idx, (di, dj) in enumerate(dire[grid[i][j]-1]):
                ni, nj = i + di, j + dj           
                if (ni >= 0 and ni < m and nj >=0 and nj < n):
                    if vis[ni][nj]: continue
                    if grid[ni][nj] not in next_dire[grid[i][j] - 1][idx]: continue
                    flag = flag or dfs(ni, nj)
            return flag

        return dfs(0, 0)
```
