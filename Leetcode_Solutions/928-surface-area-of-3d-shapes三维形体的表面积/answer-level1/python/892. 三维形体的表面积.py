### 解题思路
res = 立方体个数*6 - 重叠面积*2 
注意重叠部分为较小的数量乘上2

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        toge = 0
        summ = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                summ += grid[i][j]*6
                toge += (grid[i][j] -1)*2                
                if i+1 < m:
                    toge += min(grid[i][j], grid[i+1][j]) *2
                if j+1 < n:
                    toge += min(grid[i][j], grid[i][j+1]) *2
                # print(grid[i][j], summ, toge)
        return summ - toge
                
```