### 解题思路
O（n^2）

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let res = 0
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (j == 0) res = res + grid[i][j]
            else if(grid[i][j] - grid[i][j - 1] > 0) res = res + (grid[i][j] - grid[i][j - 1])
            if (grid[i][j] > 0) res = res + 2
            if (j == grid[0].length - 1) res = res + grid[i][j]
            else if(grid[i][j] - grid[i][j + 1] > 0) res = res + (grid[i][j] - grid[i][j + 1])
        }
    }
    for (let i = 0; i < grid[0].length; i++) {
        for (let j = 0; j < grid.length; j++) {
            if (j == 0) res = res + grid[j][i]
            else if(grid[j][i] - grid[j - 1][i] > 0) res = res + (grid[j][i] - grid[j - 1][i])
            if (j == grid.length - 1) res = res + grid[j][i]
            else if(grid[j][i] - grid[j + 1][i] > 0) res = res + (grid[j][i] - grid[j + 1][i])
        }
    }
    return res
};
```