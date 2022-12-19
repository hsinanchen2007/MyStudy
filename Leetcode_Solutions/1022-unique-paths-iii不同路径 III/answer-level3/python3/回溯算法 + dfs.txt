### 解题思路
先遍历一遍数组，找到初始位置和结束位置，用字典记录每个位置的初始状态，障碍物，起始位置初始为True，其他为False。
dfs时从起始位置开始遍历，并修改每个遍历点的状态，如果到达结束位置，并且所有状态都为True，则是一条路径。遍历到结束位置后，
回溯到上一个点，将状态重新修改为False，找新路径继续遍历。

### 代码

```python3
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        from collections import defaultdict
        # 先确定起始和结束位置，并用dict存储每个位置是否变量，初始障碍为True
        start = None
        end = None
        visited_dict = defaultdict(bool)
        row = len(grid)
        col = len(grid[0])

        # 处理初始位置，结束位置和dict初始值
        for i in range(row):
            for j in range(col):
                flag = False
                if grid[i][j] == 1:
                    start = (i, j)
                elif grid[i][j] == 2:
                    end = (i, j)
                # 是障碍物的情况
                elif grid[i][j] == -1:
                    flag = True
                visited_dict[(i, j)] = flag

        visited_dict[(start[0], start[1])] = True
        self.counter = 0
        self.backtrack(start, end, visited_dict, row, col, grid)
        return self.counter

    def backtrack(self, cur, end, visited_dict, row, col, grid):
        if cur == end and all(visited_dict.values()):
            self.counter += 1
            return

        for x, y in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            tmp_i = x + cur[0]
            tmp_j = y + cur[1]
            if 0 <= tmp_i < row and 0 <= tmp_j < col and grid[tmp_i][tmp_j] != -1:
                if visited_dict[(tmp_i, tmp_j)]:
                    continue
                visited_dict[(tmp_i, tmp_j)] = True
                self.backtrack((tmp_i, tmp_j), end, visited_dict, row, col, grid)
                visited_dict[(tmp_i, tmp_j)] = False
```