解题思路：对岛屿【为0的点】进行简单遍历【DFS】；需要对所有为0的点都遍历，对于越界的情况，就判断其所在连通域不是岛屿即可。
1、对二维矩阵所有的点进行遍历：寻找连通域
2、遍历采用DFS，在4个方向上搜索，只要遍历为0的点
3、如果新位置越界，则表明当前点在边界上，即当前点所在的连通域不是封闭岛屿；
![1.png](https://pic.leetcode-cn.com/8d0dfdae48938c850cf36cbe6a1d27ca0c03dbe1600015f65fbb3de1c2676a3b-1.png)


```
from typing import List

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        # 判断边界条件
        if not grid:
            return 0

        def dfs(grid, row, col, visited, directions):
            # 探索四周
            for direction in directions:
                new_row = row + direction[0]
                new_col = col + direction[1]
                # 判断是否越界
                if self.bound(grid, new_row, new_col):
                    nonlocal flag  # 局部变量，需要在函数嵌套里
                    flag = 0
                else:
                    # 判断是否为陆地&是否已经访问过
                    if not grid[new_row][new_col] and not visited[new_row][new_col]:
                            visited[new_row][new_col] = 1  # 标记
                            dfs(grid, new_row, new_col, visited, directions)


        # 定义方向
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        m = len(grid)  # 行
        n = len(grid[0])  # 列
        visited = [[0 for _ in range(n)] for _ in range(m)]  # 访问标记
        num = 0  # 岛屿数量

        # 遍历每个可能的连通域
        for row in range(0, m):
            for col in range(0, n):
                # 判断是否为陆地&访问过
                if grid[row][col] == 0 and visited[row][col] == 0:
                    visited[row][col] = 1  # 标记
                    # 如果构成一个岛屿，则数量加1
                    flag = 1
                    dfs(grid, row, col, visited, directions)
                    num += flag
        return num

    def bound(self, grid, new_row, new_col):
        m = len(grid)  # 行
        n = len(grid[0])  # 列
        if 0 <= new_row < m and 0 <= new_col < n:
            return False
        return True
```