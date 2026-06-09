### 解题思路
执行用时 :84 ms, 在所有 Python3 提交中击败了99.00%的用户
内存消耗 :16.3 MB, 在所有 Python3 提交中击败了18.33%的用户

从0开始进行BFS
### 代码

```python3
from collections import deque


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        INF = 2**31 - 1
        if not rooms:
            return []
        queue = deque()
        for i in range(len(rooms)):
            for j in range(len(rooms[0])):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        if len(queue) == 0:
            print('no door')
            return rooms

        while queue:
            row, col = queue.popleft()
            # print(row, col, rooms[row][col], rooms)
            if row-1 >= 0 and rooms[row-1][col] == INF:  # 左
                queue.append((row-1, col))
                rooms[row-1][col] = rooms[row][col] + 1
            if row+1 < len(rooms) and rooms[row+1][col] == INF:  # 右
                queue.append((row+1, col))
                rooms[row+1][col] = rooms[row][col] + 1
            if col-1 >= 0 and rooms[row][col-1] == INF:  # 上
                queue.append((row, col-1))
                rooms[row][col-1] = rooms[row][col] + 1
            if col+1 < len(rooms[0]) and rooms[row][col+1] == INF:  # 下
                queue.append((row, col+1))
                rooms[row][col+1] = rooms[row][col] + 1

        return rooms
```