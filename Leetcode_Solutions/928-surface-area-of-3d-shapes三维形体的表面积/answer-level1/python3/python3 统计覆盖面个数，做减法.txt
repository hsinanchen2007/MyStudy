**思路：**
1. 先统计出所有方块的个数
2. 再统计出所有方块覆盖面的个数
3. 表面积 = 方块个数(blocks) * 6 - 覆盖面个数(cover) * 2

```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        # 思路：先计算所有方块的总面积，然后再算覆盖面的个数*2则为覆盖掉的面积，总-覆=表
        if not len(grid) or not len(grid[0]):
            return 0
        # 统计方块的个数
        blocks = 0
        # 统计覆盖面的个数
        cover = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                # 累加方块总数
                blocks += grid[i][j]
                # 累加自身覆盖面总数
                cover += grid[i][j] - 1 if grid[i][j] > 1 else 0
                # 累加相邻方块覆盖面
                if i > 0:
                    cover += min(grid[i-1][j], grid[i][j])
                if j > 0:
                    cover += min(grid[i][j-1], grid[i][j])
        return blocks * 6 - cover * 2
```

