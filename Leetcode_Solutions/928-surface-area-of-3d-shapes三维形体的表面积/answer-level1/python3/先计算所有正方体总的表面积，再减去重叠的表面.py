遍历grid，对于第i行第j列的网格，如果其中的正方体个数大于0
- 每个正方体6个面，该网格总的表面积就是6*grid[i][j]
- 同一个网格是叠放的，相邻的两个正方体上下两面会重叠；每叠一次，重叠的两个面不计入表面积，所以-2 * (grid[i][j] - 1)
- 相邻网格间的正方体，侧面会重叠，正方体个数较小的网格中的正方体个数就是重叠次数
    - 如果网格(i + 1, j)存在，且其正方体个数大于0，则-2 * (min(grid[i][j], grid[i + 1][j]))
    - 如果网格(i, j + 1)存在，且其正方体个数大于0，则-2 * (min(grid[i][j], grid[i][j + 1]))

```Python
class Solution:
    def surfaceArea(self, grid) -> int:
        ans = 0
        for i, l in enumerate(grid):
            for j, _ in enumerate(l):
                # 如果网格中的正方体个数大于0
                if grid[i][j]:
                    # 每个正方体有6面，表面积为6；
                    # 因为v个正方体是叠放的，就有v-1次重叠，每次重叠少了两个面，表面积-2；
                    ans += 6 * grid[i][j] - 2 * (grid[i][j] - 1)
                # 除了叠放会造成重叠，还有网格之间的相邻也会造成重叠
                    # 如果下一行还有网格
                    if i + 1 < len(grid) and grid[i+1][j]:
                        # 相邻网格中，正方体较小的，其正方体个数就是重叠次数
                        ans -= 2 * min(grid[i][j], grid[i+1][j])
                    # 如果下一列还有网格
                    if j + 1 < len(l) and grid[i][j+1]:
                        ans -= 2 * min(grid[i][j], grid[i][j+1])
        return ans
```
