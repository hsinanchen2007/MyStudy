### 解题思路
此处撰写解题思路

我是按一列一列放置来计算的，然后再减去每次放置后重叠的面积


### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        area = 0
        # 第一行的方块只有左边会重叠，前面不会重叠所以单独拿出来计算
        area += sum([_ * 4 + 2 for _ in grid[0] if _])
        #一行中只有两列或两列以上才需要减去被遮挡部分
        if len(grid[0]) > 1:
            area -= sum([min(grid[0][cloIndex - 1], grid[0][cloIndex]) * 2 for cloIndex in range(1, len(grid[0]))])

        #计算其它行
        for rowIndex in range(1, len(grid)):
            #先加上所有列增加的面积
            area += sum([_ * 4 + 2 for _ in grid[rowIndex] if _])
            #减去左边重叠的面积，木桶原理被遮挡部分以方块少的列的为准
            area -= sum([min(grid[rowIndex][cloIndex - 1], grid[rowIndex][cloIndex]) * 2 for cloIndex in
                         range(1, len(grid[rowIndex]))])
            #减去和前面一行重叠的部分，同样以每一列方块少的列为准
            area -= sum([min(grid[rowIndex - 1][cloIndex], grid[rowIndex][cloIndex]) * 2 for cloIndex in
                 range(len(grid[rowIndex]))])
        return area
```