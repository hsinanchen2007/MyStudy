### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if not grid:return 0
        # 顶部 + 底部 + 横着看(每行) +竖着看(每列)
        # 每行
        isum = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # 加上顶部和底部
                if grid[i][j] > 0:
                    isum += 2
                if j == 0:
                    isum += grid[i][j]
                if j == len(grid[0]) - 1:
                    isum += grid[i][j]
                elif grid[i][j + 1] != grid[i][j]:
                    isum += abs(grid[i][j + 1] - grid[i][j])
        # 每列
        for j in range(len(grid[0])):
            for i in range(len(grid)):
                if i == 0:
                    isum += grid[i][j]
                if i == len(grid) - 1:
                    isum += grid[i][j]
                elif grid[i + 1][j] != grid[i][j]:
                    isum += abs(grid[i + 1][j] - grid[i][j])
        return isum
                    
                

```