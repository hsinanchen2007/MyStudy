
![SZH0PD2OIXYUA{FFX~0NXL9.png](https://pic.leetcode-cn.com/f8d2f5f0ec9a2b8f41c7d4103007ec3a61f18c9930f76c34b5af4f2246bca236-SZH0PD2OIXYUA%7BFFX~0NXL9.png)

```python
from collections import deque
class Solution(object):
    def __init__(self):
        # 设定四个遍历方向 
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        if not rooms: return rooms
        m, n = len(rooms), len(rooms[0])
        # 标记已访问
        marked = [[False for _ in range(n)] for _ in range(m)]

        queue = deque()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    marked[i][j] = True
                    queue.append((i, j))
                elif rooms[i][j] == -1:
                    marked[i][j] = True
        self.__BFS(queue, rooms, m, n, marked)
        return

    def __BFS(self, queue, rooms, m, n, marked):
        step = 0
        while queue:
            step +=1
            times = len(queue)
            for _ in range(times):
                x, y = queue.popleft()
                for direciton in self.directions:
                    new_x = x + direciton[0]
                    new_y = y + direciton[1]
                    if 0 <= new_x <= m - 1 and 0 <= new_y <= n - 1 and not marked[new_x][new_y]:
                        rooms[new_x][new_y] = step
                        marked[new_x][new_y]= True
                        queue.append((new_x,new_y))
```