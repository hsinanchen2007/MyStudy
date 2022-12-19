```
var surfaceArea = function(grid) {
    let res = 0
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            // 没有单元格则进入下一个循环
            if (grid[i][j] <= 0) continue
            // 计算叠加单元格的面积
            res += (6 * grid[i][j] - (grid[i][j] - 1) * 2)
            // 下面分别减去相邻贴合的面积
            if (j > 0) {
                res -= Math.min(grid[i][j - 1], grid[i][j]) * 2       
            }
            if (i > 0) {
                res -= Math.min(grid[i - 1][j], grid[i][j]) * 2       
            }
        }
    }
    return res
};
```