![image.png](https://pic.leetcode-cn.com/12571f208779b6bf6d4b94107a03108e245308e73bbe29f0247b8279918689c4-image.png)

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let row = grid.length;
    if(row === 0) return 0;
    let col = grid[0].length;
    if(col === 0) return 0;
    let num = 0;
    function find(x, y) {
        if(grid[x][y] == "0") return 0;
        //去重标记 避免二次处理
        grid[x][y] = "0";
        if(x - 1 >= 0 && grid[x - 1][y] === "1") find(x - 1, y);
        if(x + 1 < row && grid[x + 1][y] === "1") find(x + 1, y);
        if(y - 1 >= 0 && grid[x][y - 1] === "1") find(x, y - 1);
        if(y + 1 < col && grid[x][y + 1] === "1") find(x, y + 1);
        return 1
    }
    for(let i = 0; i < row; i ++) {
        for(let j = 0; j < col; j ++) {
            if(grid[i][j] == "1") {
                num += find(i, j)
            }
        }
    }
    return num;
};
```