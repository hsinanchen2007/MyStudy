### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def __init__(self):
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        minute = 0
        import copy
        while not self.valid(grid):
            minute += 1  # 所有== 2 的会同时腐烂
            bad = []
            pre = copy.deepcopy(grid)
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 2:  # 找出第一次全部的坏橘子
                        bad.append((i, j))
            for item in bad:
                self.single_bfs(grid, item[0], item[1])
            # 如果前后两个grid相等 那么就是根本没变化 就是无法达到的时候了
            if pre == grid:
                return -1
        return minute

    # 是否全部腐烂了
    def valid(self, grid: List[List[int]]):
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return False
        return True

    def single_bfs(self, grid: List[List[int]], i: int, j: int):
        # 每次只进行一次 扩展
        for direction in self.directions:
            ni = i + direction[0]
            nj = j + direction[1]
            if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]) \
                    and grid[ni][nj] == 1:
                # 新鲜橘子变为腐烂橘子
                grid[ni][nj] = 2

```