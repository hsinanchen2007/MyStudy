思路是统计陆地的位置, 入队, 记录陆地的位置对应距离为0
然后出队, 搜索四个方向是否是海, 记录已经被搜索过的节点,  对新的节点入队,
代码比较简单直观
```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        if not grid:
            return - 1
        from collections import deque
        # visited 统计访问过的节点
        visited = set()
        # 队列保存 出发 的节点
        que = deque()
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j]:
                    # 如果是陆地, 入队, 并记录该节点已经被访问过
                    que.append((i, j, 0))
                    visited.add((i, j))

        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))
        # 全 0 或者 全 1 的情况需要判断
        if not que or len(visited) == row * col:
            return -1
        res = 0
        while que and len(visited) != row * col:
            # 当前节点的xy位置和距离
            x, y, cnt = que.popleft()
            # 从4个方向探索
            for dx, dy in dirs:
                xx = x + dx
                yy = y + dy
                # 被探索的位置 合法/没有被记录/是海洋
                if -1 < xx < row and -1 < yy < col and (xx, yy) not in visited and grid[xx][yy] == 0:
                    visited.add((xx, yy))
                    # 统计当前的最大路径
                    res = max(res, cnt + 1)
                    # 被探索的位置, 带着当前的路径入队
                    que.append((xx, yy, cnt + 1))
        return res
```