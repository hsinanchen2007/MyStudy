解题思路：
1、对每个点都要遍历，都可能作为头
2、对于遍历过的点，要标记已访问过；用一个area去记录其面积
3、使用DFS进行遍历

解题流程：
1、判断边界条件
2、初始化访问列表
3、对每个点进行判断：是否为岛屿and未访问。满足条件则dfs
	a.初始化面积
    b.探索4个方向
    c.判断某个位置是否越界or已访问
    d.不满足c的，跳过；否则，记录面积，标记该位置，并进行dfs
4、每次遍历完一个完整岛屿，都要比较最大的面积
5、返回最大面积


```
from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # 判断边界条件
        if not grid:
            return 0

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # 方向
        max_area = 0  # 计算最大面积
        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        #  递归dfs
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                #  如果这个岛屿还没探索过，则进行dfs
                if grid[row][col] == 1 and visited[row][col] == 0:
                    grid[row][col] = -1  # 标记开头
                    area = self.dfs(grid, row, col, directions, visited) + 1
                    # 记录最大面积
                    if area > max_area:
                        max_area = area

        return max_area

    def dfs(self, grid, row, col, directions, visited):
        # 探索4个方向
        area = 0
        for direction in directions:
            new_row = row + direction[1]
            new_col = col + direction[0]

            # 判断是否越界or已经访问过
            if self.check(len(grid), len(grid[0]), new_row, new_col, visited):
                if grid[new_row][new_col] == 1:
                    area += 1  # 记录面积
                    visited[new_row][new_col] = 1  # 访问标记
                    area += self.dfs(grid, new_row, new_col, directions, visited)  # 递归
        return area

    def check(self, m, n, new_row, new_col, visited):
        if new_col < 0 or new_col >= n or new_row < 0 or new_row >= m:
            return False
        elif visited[new_row][new_col] == 1:
            return False
        return True
```