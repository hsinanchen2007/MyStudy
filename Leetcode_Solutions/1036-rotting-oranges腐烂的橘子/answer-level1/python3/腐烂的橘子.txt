### 解题思路
执行用时 :56 ms, 在所有 Python3 提交中击败了73.95%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了17.24%的用户

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: 'List[List[int]]') -> 'int':
        x, y, res = len(grid), len(grid[0]), 0
        locs, stack = [[-1, 0], [0, -1], [0, 1], [1, 0]], []
        for i in range(x):
            for j in range(y):
                if grid[i][j] == 2:
                    stack.append((i, j, 0))
        while stack:
            i, j, res = stack.pop(0)
            for loc in locs:
                loc_i, loc_j = i+loc[0], j+loc[1]
                if 0 <= loc_i < x and 0 <= loc_j < y and grid[loc_i][loc_j]== 1:
                    grid[loc_i][loc_j] = 2
                    stack.append((loc_i, loc_j, res+1))
        for i in range(x):
            for j in range(y):
                if grid[i][j] == 1:
                    return -1
        return res

```