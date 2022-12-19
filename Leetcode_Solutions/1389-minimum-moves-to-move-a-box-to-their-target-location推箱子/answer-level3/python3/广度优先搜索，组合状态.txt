### 解题思路
-   广度优先搜索

将`box`和`human`的坐标组合成状态，每一个状态有下面两种操作：

-   判断能够进行转向，也就是`human`在`box`其他方位，转向的时候步数不变
-   判断能否前进一步，能前进步数加一



其中需要判断`human`首先能够走到目标位置，这里有两种方式判断：

-   使用广度优先判断
-   首先使用`tarjan`找出强连通分量，如果`huamn`前进的位置是关键连接，用`box`的位置判断能够到达即可



这里使用的是广度优先判断`human`能否到达





### 代码

```python
from collections import deque


class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        row, col = len(grid), len(grid[0])
        human_pos = [0, 0]
        box_pos = [0, 0]
        target_pos = [0, 0]
        visited = set()

        for i in range(row):
            for j in range(col):
                if grid[i][j] == "S":
                    human_pos = [i, j]
                if grid[i][j] == "T":
                    target_pos = [i, j]
                if grid[i][j] == "B":
                    box_pos = [i, j]

        # 上下左右-坐标
        surround = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # 坐标验证
        def available(m, n):
            return 0 <= m < row and 0 <= n < col

        def human_to_go(x, y, tx, ty):
            """
            判断人能否从 [x,y] 到达 [tx,ty]
            :param x: 起始横坐标
            :param y: 起始纵坐标
            :param tx: 目标横坐标
            :param ty: 目标纵坐标
            :return:
            """
            if not available(x, y) or not available(tx, ty) or grid[x][y] != "." or grid[tx][ty] != ".":
                return False
            cur_queue = deque([(x, y)])
            cur_visited = {(x, y), }
            while cur_queue:
                cur_x, cur_y = cur_queue.popleft()
                if cur_x == tx and cur_y == ty:
                    return True
                for dx, dy in surround:
                    nx, ny = cur_x + dx, cur_y + dy
                    if (nx, ny) not in cur_visited and available(nx, ny) and grid[nx][ny] == '.':
                        cur_visited.add((nx, ny))
                        cur_queue.append((nx, ny))
            return False

        grid[target_pos[0]][target_pos[1]] = '.'
        grid[human_pos[0]][human_pos[1]] = '.'
        grid[box_pos[0]][box_pos[1]] = '#'

        d = deque()

        for di, dj in surround:
            ni, nj = box_pos[0] + di, box_pos[1] + dj
            if (box_pos[0], box_pos[1], ni, nj) not in visited and human_to_go(*human_pos, ni, nj):
                visited.add((box_pos[0], box_pos[1], ni, nj))
                d.append((box_pos[0], box_pos[1], ni, nj, 0))
        grid[box_pos[0]][box_pos[1]] = '.'

        while d:

            box_x, box_y, human_x, human_y, steps = d.popleft()
            if box_x == target_pos[0] and box_y == target_pos[1]:
                return steps
            # 尝试切换方向
            grid[box_x][box_y] = "#"
            for di, dj in surround:
                ni, nj = box_x + di, box_y + dj
                if (box_x, box_y, ni, nj) not in visited and human_to_go(human_x, human_y, ni, nj):
                    visited.add((box_x, box_y, ni, nj))
                    d.append((box_x, box_y, ni, nj, steps))

            grid[box_x][box_y] = "."
            # 尝试前进一步
            if box_x == human_x:
                # 垂直移动
                if box_y > human_y:
                    # 向上移动
                    if available(box_x, box_y + 1) and grid[box_x][box_y + 1] == "." and (box_x, box_y + 1, box_x, box_y) not in visited:
                        visited.add((box_x, box_y + 1, box_x, box_y))
                        d.append((box_x, box_y + 1, box_x, box_y, steps + 1))
                else:
                    # 向下移动
                    if available(box_x, box_y - 1) and grid[box_x][box_y - 1] == "." and (box_x, box_y - 1, box_x, box_y) not in visited:
                        visited.add((box_x, box_y - 1, box_x, box_y))
                        d.append((box_x, box_y - 1, box_x, box_y, steps + 1))

            else:
                # 水平移动
                if box_x > human_x:
                    # 向右移动
                    if available(box_x + 1, box_y) and grid[box_x + 1][box_y] == "." and (box_x + 1, box_y, box_x, box_y) not in visited:
                        visited.add((box_x + 1, box_y, box_x, box_y))
                        d.append((box_x + 1, box_y, box_x, box_y, steps + 1))
                else:
                    # 向左移动
                    if available(box_x - 1, box_y) and grid[box_x - 1][box_y] == "." and (box_x - 1, box_y, box_x, box_y) not in visited:
                        visited.add((box_x - 1, box_y, box_x, box_y))
                        d.append((box_x - 1, box_y, box_x, box_y, steps + 1))
        return -1
```