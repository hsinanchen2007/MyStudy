### 解题思路
> 执行用时 :60 ms, 在所有 Python3 提交中击败了57.78%的用户
> 内存消耗 :13.4 MB, 在所有 Python3 提交中击败了17.24%的用户

- 把当前的属于2的记录下来
- 遍历周围的是1的, 再记录下来, 然后次数加一, 循环直到周围已经没有1了

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        queue = list()
        rotting_pos = []
        for row, cols in enumerate(grid):
            for col, value in enumerate(cols):
                if value == 2:
                    rotting_pos.append((row, col))
        queue.append(rotting_pos)

        times = 0
        while len(queue) > 0:
            rotting_pos = []
            current_li = queue.pop(0)
            for x, y in current_li:
                grid[x][y] = 0
                around = ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1))
                for nr, nc in around:
                    if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1 and ((nr, nc) not in current_li):
                        rotting_pos.append((nr, nc))
            if rotting_pos:
                queue.append(rotting_pos)
                times += 1

        for cols in grid:
            for v in cols:
                if v == 1:
                    return -1
        return times
```