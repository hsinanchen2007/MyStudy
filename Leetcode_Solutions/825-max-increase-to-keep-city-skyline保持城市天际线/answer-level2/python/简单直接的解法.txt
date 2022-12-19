### 解题思路
3次遍历
1. 遍历每一行记录当前行的最大值；
2. 遍历每一列记录当前列的最大值；
3. 遍历每个数字，当前数字最大可为当前列和行的记录的两个值的最小值。

### 代码

```python3
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        nrows = len(grid)
        ncols = len(grid[0])
        rowdict = dict()
        coldict = dict()
        for subrow in range(nrows):
            rowdict[subrow] =0
            for subcol in range(ncols):
                if grid[subrow][subcol] > rowdict[subrow]:
                    rowdict[subrow] = grid[subrow][subcol]
        
        for subcol in range(ncols):
            coldict[subcol] = 0
            for subrow in range(nrows):
                if grid[subrow][subcol] > coldict[subcol]:
                    coldict[subcol] = grid[subrow][subcol]
        
        total = 0
        for subrow in range(nrows):
            for subcol in range(ncols):
                min1 = min([rowdict[subrow],coldict[subcol]])
                    total += (min1-grid[subrow][subcol])

        return total
```