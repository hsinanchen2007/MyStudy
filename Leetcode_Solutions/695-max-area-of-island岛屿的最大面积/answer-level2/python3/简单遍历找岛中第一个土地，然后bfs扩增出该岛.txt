### 解题思路
> 循环查找每一个位置， 如果是土地，则用bfs衍生出周边的点，找到一个岛，并标记当前岛屿包含的所有点位， 下一次找到另一个小岛的土地位置时， 类似方法找出该岛并计算大小，直到所有点都被访问；

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        height = len(grid)
        width = len(grid[0])
        visited = {}
        biggest = 0
        adj_rule = ((-1, 0), (1, 0), (0, -1), (0, 1))

        def is_valid(x, y):
            return 0 <= x < height and 0 <= y < width

        def get_adj_pos(i, j):
            adj = []
            for x, y in adj_rule:
                pos = (i + x, j + y)
                if not is_valid(pos[0], pos[1]):
                    continue
                if grid[pos[0]][pos[1]] == 0 or pos in visited:
                    continue
                adj.append(pos)
            return adj

        for i, row in enumerate(grid):
            for j, col in enumerate(row):
                if grid[i][j] == 0 or (i, j) in visited:
                    continue
                q = [(i, j)]
                earth = 0
                while q:
                    x, y = q.pop()
                    if (x, y) in visited:
                        continue
                    earth += 1
                    if earth > biggest:
                        biggest = earth
                    visited[(x, y)] = earth
                    q.extend(get_adj_pos(x, y))

        return biggest

```

# 运行情况
- 不知道为啥，用时比较多， 感觉算法应该效率比较高才对。。。
```
执行用时 :268 ms, 在所有 Python3 提交中击败了12.00%的用户
内存消耗 :14 MB, 在所有 Python3 提交中击败了68.06%的用户
```