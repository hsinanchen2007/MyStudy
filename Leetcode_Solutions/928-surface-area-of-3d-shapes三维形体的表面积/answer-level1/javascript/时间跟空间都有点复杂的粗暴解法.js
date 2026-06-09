
```
var surfaceArea = function (grid) {
    let area = 0;
    for (var i in grid) {
        for (var j in grid[i]) {
            if (grid[i][j] != 0) {
                area += 4 * grid[i][j] + 2 - (grid[i - 1] ? Math.min(grid[i - 1][j], grid[i][j]) * 2 : 0) - (grid[i][j - 1] ? Math.min(grid[i][j - 1], grid[i][j]) * 2 : 0)
            }
        }
    }

    return area
};
```
首先就是遍历长宽，然后计算面积，完啦！
这个题读了半天才明白意思，二维数组分别代表grid[i][j],v=grid[i][j]表示坐标为(i,j)的地方有v个小方块，我选择从右上角开始计算，然后依次向右上减去重叠的面积！


