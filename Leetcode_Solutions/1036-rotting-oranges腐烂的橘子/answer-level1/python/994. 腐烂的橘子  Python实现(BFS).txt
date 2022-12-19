### 解题思路
主要运用了Flood Fill算法。初始将所有腐烂的橘子入队列。每一次往外延伸一层, 将临接的新鲜橘子置为腐烂。直到完成(队列为空), 记下用时(层数)。注意如果所有初始单元格为空, 返回0。

### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque
        queue = deque()
        # 找到初始所有的腐烂橘子
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    queue.append((i, j, 0)) # 将腐烂橘子加入队列
        d = 0
        while queue:
            count = len(queue)
            for _ in range(count):  # 将当前层pop
                i, j, d = queue.popleft()
                if i - 1 >= 0 and grid[i - 1][j] == 1:  # 上邻居符合条件
                    grid[i - 1][j] = 2
                    queue.append((i - 1, j, d + 1))
                if i + 1 < len(grid) and grid[i + 1][j] == 1:   # 下邻居符合条件
                    grid[i + 1][j] = 2
                    queue.append((i + 1, j, d + 1))
                if j - 1 >= 0 and grid[i][j - 1] == 1:  # 左邻居符合条件
                    grid[i][j - 1] = 2
                    queue.append((i, j - 1, d + 1))
                if j + 1 < len(grid[0]) and grid[i][j + 1] == 1:    # 右邻居符合条件
                    grid[i][j + 1] = 2
                    queue.append((i, j + 1, d + 1))
     
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1   # 只要有一个新鲜橘子, 就返回-1
        return d  # 返回最终经过的时间            
```


```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque
        queue = deque()
        # 找到初始所有的腐烂橘子
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    queue.append((i, j)) # 将腐烂橘子加入队列
        d = -1
        while queue:
            d += 1
            count = len(queue)
            for _ in range(count):  # 将当前层pop
                i, j = queue.popleft()
                if i - 1 >= 0 and grid[i - 1][j] == 1:  # 上邻居符合条件
                    grid[i - 1][j] = 2
                    queue.append((i - 1, j))
                if i + 1 < len(grid) and grid[i + 1][j] == 1:   # 下邻居符合条件
                    grid[i + 1][j] = 2
                    queue.append((i + 1, j))
                if j - 1 >= 0 and grid[i][j - 1] == 1:  # 左邻居符合条件
                    grid[i][j - 1] = 2
                    queue.append((i, j - 1))
                if j + 1 < len(grid[0]) and grid[i][j + 1] == 1:    # 右邻居符合条件
                    grid[i][j + 1] = 2
                    queue.append((i, j + 1))
     
        count0 = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1   # 只要有一个新鲜橘子, 就返回-1
                elif grid[i][j] == 0:
                    count0 += 1
        # 返回最终经过的时间(如果初始所有单元格都为0, 返回0)
        return d if count0 != len(grid) * len(grid[0]) else 0  
```