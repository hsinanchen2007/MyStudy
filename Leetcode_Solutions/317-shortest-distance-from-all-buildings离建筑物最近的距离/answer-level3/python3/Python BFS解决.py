


```
'''
多路BFS求每个点到所有1位置距离和最小值
'''

from typing import List
from queue import Queue
class Solution:

    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) if len(grid) != 0 else 0
        if m == 0 or n == 0:
            return -1

        que = Queue()
        visited = [[[[0] * n for _ in range(m)] for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    que.put_nowait((i, j, i, j, 0))        # 状态 (起点i, 起点j，当前i, 当前j, 开销)
                    visited[i][j][i][j] = 1

        start_node_num = que.qsize()
        # 记录到每个点最短路径的累加和，键是点坐标. 值是[累加路径和，累加次数]
        rec = [[[0, 0] for _ in range(n)] for _ in range(m)]

        while not que.empty():
            start_i, start_j, cur_i, cur_j, payload = que.get_nowait()
            if grid[cur_i][cur_j] == 0:
                rec[cur_i][cur_j][0] += payload
                rec[cur_i][cur_j][1] += 1

            for ii, jj in [(cur_i-1, cur_j), (cur_i+1, cur_j), (cur_i, cur_j+1), (cur_i, cur_j-1)]:
                if ii >= 0 and ii < m and jj >= 0 and jj < n:
                    if grid[ii][jj] == 0 and visited[start_i][start_j][ii][jj] == 0:
                        visited[start_i][start_j][ii][jj] = 1
                        que.put_nowait((start_i, start_j, ii, jj, payload + 1))

        ans = 0x7fffffff
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and rec[i][j][1] == start_node_num:
                    ans = min(ans, rec[i][j][0])

        return ans if ans != 0x7fffffff else -1

```
