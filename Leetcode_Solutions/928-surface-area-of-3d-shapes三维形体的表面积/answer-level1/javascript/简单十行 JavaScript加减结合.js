
``` javascript
var surfaceArea = function(grid) {
    var [n, sum, r, c] = [grid.length, 0];
    if (!n) return sum;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (grid[r][c] > 0) sum += 4 * grid[r][c] + 2;
            if (r - 1 >= 0) sum -= 2 * (Math.min(grid[r][c], grid[r - 1][c]));
            if (c - 1 >= 0) sum -= 2 * (Math.min(grid[r][c], grid[r][c - 1]));
        }
    }
    return sum;
};
```

先把每一单元格的块组抽离来看
其表面积是4倍的侧面积加上下底面积
sum += 4n + 2

再减去相邻的重叠面积
sum -= 2n