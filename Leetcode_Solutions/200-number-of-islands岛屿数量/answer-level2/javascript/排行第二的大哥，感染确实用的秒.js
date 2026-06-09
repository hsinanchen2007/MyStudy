### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const row = grid.length;
    if (!row) return 0;
    if(!grid[0])return 0;
    const col = grid[0].length;
    let landNum = 0;

    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            const cur = grid[r][c];
            if (cur == 1) {
                landNum++;
                inject(grid, r, c);
            }
        }
    }

    function inject(grid, i, j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        inject(grid, i - 1, j);
        inject(grid, i + 1, j);
        inject(grid, i, j - 1);
        inject(grid, i, j + 1);
    }
    return landNum;
};
```