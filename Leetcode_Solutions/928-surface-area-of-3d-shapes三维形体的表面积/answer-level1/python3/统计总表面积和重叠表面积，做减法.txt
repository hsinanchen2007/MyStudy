首先对于每个立方体块的表面积是6，但是立方体快堆叠在一起会出现重叠部分。
分析重叠部分有两种：一种在同位置上往上堆叠，比如单个2，假设周围没有立方块，其重叠的表面积为（2-1）* 2。第二种是周围重叠比如[2, 4]，对于2因为左边有个4，重叠的部分为min(2,4)。
所以整体解题思路是计算有多少个立方块total，得到总的表面积为6 * total，统计重叠的面积为sub，最终的结果就是total * 6 - sub。

```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        row = len(grid)
        if row == 0:
            return 0
        col = len(grid)

        total = 0
        sub = 0

        for i in range(row):
            for j in range(col):
                if grid[i][j] != 0:
                    total += grid[i][j]  # 统计立方体块
                    sub += (grid[i][j] - 1) * 2  # 统计第一种重叠的表面积
                    for direction in directions:
                        new_i, new_j = i + direction[0], j + direction[1]
                        if 0 <= new_i < row and 0 <= new_j < col:
                            sub += min(grid[i][j], grid[new_i][new_j])  # 统计第二种重叠的表面积
        return total * 6 - sub
```
