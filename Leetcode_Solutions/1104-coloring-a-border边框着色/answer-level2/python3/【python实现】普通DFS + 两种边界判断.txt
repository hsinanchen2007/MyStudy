解题思路：只需要一个普通的DFS，然后再判断当前位置是否是矩形边界or四周存在非联通量
![1.png](https://pic.leetcode-cn.com/df869a92306b258bd282105030bf49f28bd809675132e8eb92ac22c4b3137549-1.png)

```
from typing import List


class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        # 边界条件判断
        if not grid:
            return []

        def dfs(row, col):
            # 判断是否为矩阵边界:着色
            if row == 0 or col == 0 or row == m - 1 or col == n - 1:
                grid[row][col] = color

            # 搜索4个方向
            for direction in directions:
                new_row = row + direction[0]
                new_col = col + direction[1]

                # 判断是否越界
                if 0 <= new_row < m and 0 <= new_col < n:
                    # 判断是否访问过
                    if not visited[new_row][new_col]:
                        # 判断是否为连通量，只要出现非连通量，则当前的位置就是边界
                        if grid[new_row][new_col] == color_:
                            visited[new_row][new_col] = 1
                            dfs(new_row, new_col)  # 深搜
                        else:
                            # 当前位置是边界，着色
                            grid[row][col] = color

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # 定义方向
        m, n = len(grid), len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]  # 访问列表

        color_ = grid[r0][c0]
        visited[r0][c0] = 1  # 访问标记
        dfs(r0, c0)  # 寻找连通分量

        return grid
```