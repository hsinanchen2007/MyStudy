因为给的是方块，所以两重循环内的数组下标互换就可以统计两个不同方向的水平投影，每行/列的投影为该行/列的最高方块柱高度；垂直投影也就是方块柱的个数，循环中判断该点有方块柱就累加1.

执行用时 : 80 ms, 在所有 JavaScript 提交中击败了 85.00% 的用户
内存消耗 : 34.5 MB, 在所有 JavaScript 提交中击败了 100.00% 的用户

```javascript []
var projectionArea = function(grid) {
    var a, b, c, n = grid.length;
    var res = 0;
    for (let i = 0; i < n; ++i) {
        let maxa = 0, maxb = 0;
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > maxa) {
                maxa = grid[i][j];
            }
            if (grid[j][i] > maxb) {
                maxb = grid[j][i];
            }
            if (grid[i][j]) {
                ++res;
            }
        }
        res += maxa;
        res += maxb;
    }
    return res;
};
```
