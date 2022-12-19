```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        from collections import deque
        # 方向矩阵
        directVec = [(-1,-1), (1,0), (0,1), (-1,0), (0,-1), (1,1), (1,-1), (-1,1)]
        # 定义队列 
        queue = deque()
        # 定义备忘录，用于记录已经访问的位置（这里直接用grid代替）
        n = len(grid)
        # 判断边界条件，是否能直接返回结果的
        if not grid or grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        elif n <= 2:
            return n
        # 将起始位置加入队列中，并同时更新备忘录
        queue.append((0, 0, 1))
        grid[0][0] = 1
        # while 队列不为空
        while queue:
            # 获取当前队列出队元素，并找他的下一个满足节点入队列
            i, j, step = queue.popleft()         
            for dx, dy in directVec:
                # 首先判断是否达到终点位置
                if i+dx == n-1 and j+dy == n-1:
                    return step + 1
                # 获取下一个节点，并条件判断 过滤掉不合条件的位置，入队列
                if 0 <= i+dx < n and 0 <= j+dy < n and grid[i+dx][j+dy] == 0:
                    queue.append((i+dx, j+dy, step+1))
                    # 更新备忘录 入队列的同时就要更新备忘录
                    grid[i+dx][j+dy] = 1                 
        return -1
```