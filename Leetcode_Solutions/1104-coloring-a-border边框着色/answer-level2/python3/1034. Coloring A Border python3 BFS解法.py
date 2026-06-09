### 解题思路
用宽度优先搜索的思路解决二维矩阵连通\最短路径问题
用collections库中的deque来创建队列

**解决步骤**
1. 创建队列从给定的坐标开始进行层级遍历，创建集合记录走过的square
2. 对于每一个队列中的square，对它的四个方向进行遍历
3. 若判断是border，进行染色
判断是否为border：
    1. 在矩阵边缘
    2. 周围存在不同色的square。
4. 不是border（即同色），进入队列，并加入已遍历的集合

### 代码

```python3
import collections
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        if not grid or len(grid[0]) == 0:
            return grid
        
        queue = collections.deque([(r0, c0)])
        cur_color = grid[r0][c0]
        visited = {(r0, c0)}
        while queue:
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for x_add, y_add in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    x_next, y_next = x + x_add, y + y_add
                    if (x_next, y_next) in visited:
                        continue
                    if self.isBorder(x_next, y_next, grid, cur_color):
                        grid[x][y] = color
                    elif grid[x_next][y_next] == cur_color:
                        queue.append((x_next, y_next))
                        visited.add((x_next, y_next))
        return grid
    

    def isBorder(self, x, y, grid, cur_color):
        if x < 0 or x > len(grid) - 1:
            return True
        elif y < 0 or y > len(grid[0]) - 1:
            return True
        elif grid[x][y] != cur_color:
            return True
        return False
``````
```python3
import collections
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        if not grid or len(grid[0]) == 0:
            return grid
        
        queue = collections.deque([(r0, c0)])
        cur_color = grid[r0][c0]
        visited = {(r0, c0)}
        while queue:
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for x_add, y_add in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    x_next, y_next = x + x_add, y + y_add
                    if (x_next, y_next) in visited:
                        continue
                    if self.isBorder(x_next, y_next, grid, cur_color):
                        grid[x][y] = color
                    elif grid[x_next][y_next] == cur_color:
                        queue.append((x_next, y_next))
                        visited.add((x_next, y_next))
        return grid
    

    def isBorder(self, x, y, grid, cur_color):
        if x < 0 or x > len(grid) - 1:
            return True
        elif y < 0 or y > len(grid[0]) - 1:
            return True
        elif grid[x][y] != cur_color:
            return True
        return False
```
```
