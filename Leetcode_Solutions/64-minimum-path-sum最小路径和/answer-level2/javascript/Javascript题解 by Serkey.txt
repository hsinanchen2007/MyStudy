```javascript
var minPathSum = function (grid) {
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let num = grid[i][j];
            let top = grid[i - 1] ? grid[i - 1][j] : 0;
            let left = grid[i][j - 1] ? grid[i][j - 1] : 0;
            if (!i) {
                top = left;
            }
            if (!j) {
                left = top;
            }
            grid[i][j] = num + left >= num + top ? num + top : num + left;
        }
    }
    return grid[grid.length - 1][grid[0].length - 1];
};
```