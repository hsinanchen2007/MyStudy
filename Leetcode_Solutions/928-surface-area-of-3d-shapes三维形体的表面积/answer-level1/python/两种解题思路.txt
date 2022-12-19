```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        """
        思路1：
        上+下面积 = 有立方体的格子个数 * 2
        前+后面积 = (每行最高的立方体之和) * 2
        左+右面积 = (每列最高的立方体之和) * 2
        
        思路2：
        每个单元格上立方体面积 = 6*高度 - 与上/左/后方贴合立方体面积*2
        """
        '''采用思路2'''
        gridlen = len(grid)
        res = 0
        
        for i in range(gridlen):
            for j in range(gridlen):
                if grid[i][j]:
                    res += 6*grid[i][j] - (grid[i][j]-1) * 2  # 减去上方贴合面积
                if i:
                    res -= min(grid[i-1][j], grid[i][j]) * 2  # 减去左方贴合面积
                if j:
                    res -= min(grid[i][j-1], grid[i][j]) * 2  # 减去后方贴合面积
        
        return res
```
