### 解题思路
1、处理特殊情况：没有任何填充的返回0，只有一个位置填充的，直接算表面积；
2、其他情况：
2.1、分为几个部分：上下面的面积，每个位置的4个侧面积，重合的侧面积；
2.2、上下面的面积计算：遍历list，只要算出有几个位置填充了，再*2即可；
2.3、每个位置的4个侧面积计算：遍历list时，遇到非0的就计算，用该位置的值*4，即为每个位置的侧面积；
2.4、重合的侧面积：因为可能相邻位置都有填充，则会有重合的部分，注意重合的部分面积是两部分，需要减去2倍的重合面积：遍历list，分别按行、按列搜索，如果相邻位置都有填充，则取最小值*2，之前计算的总面积减去这个值。

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if len(grid) == 0 or (len(grid) == 1 and len(grid[0]) == 0):
            return 0
        if len(grid) == 1 and len(grid[0]) == 1:
            return 2 + 4 * grid[0][0]
        area = 0
        count = 0
        # 遇到不为0的即算侧面积
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] != 0:
                    count += 1
                    area += grid[i][j] * 4
        # 加上上下面的面积
        area += count * 2
        # area减去重合的面积
        # 按行、按列
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if j > 0:
                    if grid[i][j] !=0 and grid[i][j-1] != 0:
                        min_num = min(grid[i][j], grid[i][j-1])
                        area -= min_num * 2
                if i > 0:
                    if grid[i][j] !=0 and grid[i-1][j] != 0:
                        min_num = min(grid[i][j], grid[i-1][j])
                        area -= min_num * 2
        return area
```