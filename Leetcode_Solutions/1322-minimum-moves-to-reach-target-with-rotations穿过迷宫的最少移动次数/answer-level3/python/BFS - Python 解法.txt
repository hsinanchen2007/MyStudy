### 思路
问最短距离/最少移动次数，一般都是用 `BFS` 解题。

所以本题也可以用 `BFS` 来解决，

跟普通的 `BFS` 有所区别的地方在于，

移动的方向不再是四方向/八方向，而变成了向右，向下和旋转，

而且现在每种状态占据的格子数不再是 `1`， 而是 `2`。

其他可能还需要注意的就是：

1. 用 `visited` 集合记录去过的格子，避免重复访问陷入死循环
2. 注意检测坐标是否还在 `n * n` 的格子范围内
3. 记得判断下次移动坐标是否有效
4. 旋转操作需要 **额外** 判断两个格子是否有效

### 代码实现
```Python []
class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        from collections import deque
        queue = deque([((0, 0), (0, 1), 0)])
        visited = set()
        
        while queue:
            pos0, pos1, step = queue.popleft()
            # print pos0, pos1
            x0, y0 = pos0
            x1, y1 = pos1
            if (x0, y0) == (n - 1, n - 2) and (x1, y1) == (n - 1, n - 1):
                return step
            if x0 == x1 and y1 > y0:# 当前水平
                # 向右走
                x2, y2 = x1, y1 + 1
                if 0 <= x2 < n and 0 <= y2 < n and ((x1, y1), (x2, y2)) not in visited and grid[x2][y2] != 1:
                    visited.add(((x1, y1), (x2, y2)))
                    queue.append(((x1, y1), (x2, y2), step + 1))
                # 向下走
                x2, y2 = x0 + 1, y0
                x3, y3 = x1 + 1, y1
                if 0 <= x2 < n and 0 <= x3 < n and 0 <= x3 < n and 0 <= y3 < n and ((x2, y2), (x3, y3)) not in visited and grid[x2][y2] != 1 and grid[x3][y3] != 1:
                    visited.add(((x2, y2), (x3, y3)))
                    queue.append(((x2, y2), (x3, y3), step + 1))
                # 旋转
                x2, y2 = x0 + 1, y0
                if 0 <= x2 < n and 0 <= y2 < n and ((x0, y0), (x2, y2)) not in visited and grid[x0 + 1][y0] != 1 and grid[x0 + 1][y0 + 1] != 1:
                    visited.add(((x0, y0), (x2, y2)))
                    queue.append(((x0, y0), (x2, y2), step + 1))
                    
            elif x1 > x0 and y0 == y1:# 当前竖直
                # 向右走
                x2, y2 = x0, y0 + 1
                x3, y3 = x1, y1 + 1
                if 0 <= x2 < n and 0 <= x3 < n and 0 <= x3 < n and 0 <= y3 < n and ((x2, y2), (x3, y3)) not in visited and grid[x2][y2] != 1 and grid[x3][y3] != 1:
                    visited.add(((x2, y2), (x3, y3)))
                    queue.append(((x2, y2), (x3, y3), step + 1))
                # 向下走
                x2, y2 = x1 + 1, y1
                if 0 <= x2 < n and 0 <= y2 < n and ((x1, y1), (x2, y2)) not in visited and grid[x2][y2] != 1:
                    visited.add(((x1, y1), (x2, y2)))
                    queue.append(((x1, y1), (x2, y2), step + 1))
                # 旋转
                x2, y2 = x0, y0 + 1
                if 0 <= x2 < n and 0 <= y2 < n and ((x0, y0), (x2, y2)) not in visited and grid[x0][y0 + 1] != 1 and grid[x0 + 1][y0 + 1] != 1:
                    visited.add(((x0, y0), (x2, y2)))
                    queue.append(((x0, y0), (x2, y2), step + 1))           
        return -1
```

### 复杂度分析：
时间复杂度：$O(N^2)$
空间复杂度：$O(N^2)$