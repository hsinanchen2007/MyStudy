

```

'''
bfs 陆地填海，最终每一个海位置数值都更新成离他最近的陆地的距离
'''


from typing import List
from queue import Queue
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        que = Queue()
        one_cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    que.put((i, j, 0))      # 状态定义为(当前i, 当前j, 总开销)
                    one_cnt += 1

        if one_cnt == 0:
            return -1

        dis = [[0x7fffffff for _ in range(n)] for _ in range(m)]
        while not que.empty():
            cur_i, cur_j, payload = que.get()
            if payload >= dis[cur_i][cur_j]:
                continue

            dis[cur_i][cur_j] = payload
            for new_i, new_j in [[cur_i-1, cur_j], [cur_i+1, cur_j], [cur_i, cur_j-1], [cur_i, cur_j+1]]:
                if new_i >= 0 and new_i < m and new_j >= 0 and new_j < n:
                    que.put((new_i, new_j, payload+1))

        ans = -1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    ans = max(ans, dis[i][j])

        return ans
```
