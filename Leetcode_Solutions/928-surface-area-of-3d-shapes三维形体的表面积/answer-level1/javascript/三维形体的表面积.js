```js
var surfaceArea = function(grid) {
    let sum = 0;
    let N = grid.length;
    for (let i = 0; i < N; i++) {
        let item = grid[i];
        // 前后重叠
        let overlap = 0;
        // 左右重叠
        let overlap2 = 0;
        // 上下重叠
        let overlap3 = 0;
        for (let k = 0; k < N - 1; k++) {
            overlap += Math.min(item[k], item[k+1]) * 2
        }
        for (let k = 0; k < N - 1; k++) {
            overlap2 += Math.min(grid[k][i], grid[k+1][i]) * 2
        }
        for (let j = 0;j < N; j++) {
            sum += grid[i][j] * 6
            if (grid[i][j] > 1) {
                overlap3 += (grid[i][j] - 1 ) * 2
            }
        }
        sum = sum - overlap - overlap2 - overlap3
    }
    return sum
};
```