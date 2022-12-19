### 解题思路
例子比较难懂,可以把数组作为一个平面理解比较好
grid = [[2]],可以理解grid[0][0] = 2
grid = [[1,2],[3,4]],可以理解grid[0][0] = 1,grid[0][1] = 2,grid[1][0] = 3,grid[1][1] = 4
grid = [[2,2,2],[2,1,2],[2,2,2]],可以理解grid[0][0] = 2,grid[0][1] = 2,grid[0][2] = 2,grid[1][0] = 2,grid[1][1] = 1,grid[1][2] = 2,grid[2][0] = 2,grid[2][1] = 2,grid[2][2] = 2

剩下的就是下面代码了


### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        result = 0
        for i, row in enumerate(grid):
            for j, num in enumerate(row):
                # 立方体上下面非0，面数=2
                top = 0
                if num > 0:
                    top = 2
                # 立方体的上下左右
                indexes = [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]
                side = 0
                for index in indexes:
                    x, y = index
                    # 立方体4周没有立方体，面数=立方体数
                    if not 0 <= x < len(grid):
                        side = side + num
                        continue
                    if not 0 <= y < len(row):
                        side = side + num
                        continue
                    # 如果这个格子的立方体大于周围立方体，面数=此立方体数-周围立方体
                    side = side + max(num - grid[x][y], 0)
                result = result + side + top
        return result
```