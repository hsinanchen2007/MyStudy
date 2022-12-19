优化的主要思想是路径上的两个端点只有可能出现在两座岛屿的边界以及已访问可通过将源数据置为-1表示而不需要额外的哈希来判断。

因此我们从任一为1的点开始BFS时，将遍历过的位置修改为-1用来避免重复访问同时收集边界点（若它的四个邻居都为1或-1，那它一定不是边界点）

那么这样BFS之后，我们只需要再对当前收集的边界点来进行一次BFS扩散，碰到1时的扩散步数即为最短距离

```python
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        a, spread, border, flag = len(A), [], [], False
        for i in range(a):
            for j in range(a):
                if A[i][j]:  # 找到任一岛屿的起始点
                    A[i][j] = -1  # 置为已访问
                    spread.append((i, j))
                    flag = True
                    break
            if flag:
                break
        step = ((-1, 0), (1, 0), (0, -1), (0, 1))
        while spread:  # bfs找该岛屿的所有部分
            i, j = spread.pop(0)
            neighbor = 0
            if i == 0 or i == a-1:
                neighbor += 1
            if j == 0 or j == a-1:
                neighbor += 1
            for di, dj in step:
                _i, _j = i+di, j+dj
                if -1 < _i < a and -1 < _j < a:
                    if A[_i][_j] == 1:
                        neighbor += 1
                        A[_i][_j] = -1  # 置为已访问
                        spread.append((_i, _j))  # 加入队列
                    elif A[_i][_j] == -1:
                        neighbor += 1
            if neighbor < 4:  # 邻居小于4则该坐标为岛屿边界点
                border.append((i, j, 0))
        while True:  # 对边界点进行BFS扩散
            i, j, n = border.pop(0)
            for di, dj in step:
                _i, _j = i+di, j+dj
                if -1 < _i < a and -1 < _j < a:
                    if not A[_i][_j]:  # 仅当该位置为0才加入队列
                        A[_i][_j] = -1  # 置为已访问
                        border.append((_i, _j, n+1))
                    elif A[_i][_j] == 1:  # 为1则找到，为-1则跳过
                        return n
```
