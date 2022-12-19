### 解题思路
此处撰写解题思路
上下左右四个方向重叠的面积减去即可，每个单元格的方块面积个数计算公式为 4n+2 = 6n-(n-1)*2 只有当n>0的时候，等于0的时候是0.

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)

        # 某个单元格垂直的方快体积是 4n+2 = 6n-(n-1)*2
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += 4*grid[i][j]+2 if grid[i][j] else 0
                if 0<=i-1:
                    ans -= min(grid[i-1][j],grid[i][j])
                if i+1<n:
                    ans -= min(grid[i+1][j],grid[i][j])
                if 0<=j-1:
                    ans -= min(grid[i][j-1],grid[i][j])
                if j+1<n:
                    ans -= min(grid[i][j+1],grid[i][j])
        return ans




```