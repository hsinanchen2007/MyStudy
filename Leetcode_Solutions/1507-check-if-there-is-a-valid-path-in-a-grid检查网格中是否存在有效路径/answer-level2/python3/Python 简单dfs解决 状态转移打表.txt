![image.png](https://pic.leetcode-cn.com/fb19073ec0e24421a9d7a876e0557b1fef529fa80a985c935900ac2b5aaaebb9-image.png)


```
'''
简单dfs解决，就是状态转移稍微有点恶心
'''

from typing import List
class Solution:

    def dfs(self, grid: List[List[int]], i, j, m, n, moves, visited) -> bool:
        if i == m-1 and j == n-1:
            return True

        visited[i][j] = 1

        for move in moves[grid[i][j]]:
            ii, jj = i + move[0], j + move[1]
            if ii < 0 or ii >= m or jj < 0 or jj >= n:
                continue

            if visited[ii][jj] or grid[ii][jj] != move[2]:
                continue

            if self.dfs(grid, ii, jj, m, n, moves, visited):
                visited[i][j] = 0
                return True

        visited[i][j] = 0
        return False

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        # 状态转移定义
        moves = {
            1: [ [0, -1, 1], [0, -1, 4], [0, -1, 6], [0, 1, 1], [0, 1, 3], [0, 1, 5] ],
            2: [ [-1, 0, 2], [-1, 0, 3], [-1, 0, 4], [1, 0, 2], [1, 0, 5], [1, 0, 6] ],
            3: [ [0, -1, 1], [0, -1, 4], [0, -1, 6], [1, 0, 2], [1, 0, 5], [1, 0, 6] ],
            4: [ [1, 0, 2], [1, 0, 5], [1, 0, 6], [0, 1, 1], [0, 1, 3], [0, 1, 5] ],
            5: [ [0, -1, 1], [0, -1, 4], [0, -1, 6], [-1, 0, 2], [-1, 0, 3], [-1, 0, 4] ],
            6: [ [-1, 0, 2], [-1, 0, 3], [-1, 0, 4], [0, 1, 1], [0, 1, 3], [0, 1, 5] ]
        }

        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        return self.dfs(grid, 0, 0, len(grid), len(grid[0]), moves, visited)
```
