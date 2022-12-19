解法一：
    核心思想： 查看每一个为1的格子的上下左右四个面， 如果遭遇边界或者遭遇为0的格子，则周长加一

```javascript
var islandPerimeter = function(grid) {
    let row = grid.length;
    let col = grid[0].length;
    let len = 0;

    function find(x, y) {
        //遭遇边界  果断加一
        if(x - 1 < 0) len ++;
        if(x + 1 >= row) len ++;
        if(y - 1 < 0) len ++;
        if(y + 1 >= col) len ++;
        //不在边界  判断上下左右是如果为零  果断加一 
        if(x - 1 >= 0 && grid[x - 1][y] === 0) len ++;
        if(x + 1 < row && grid[x + 1][y] === 0 ) len ++;
        if(y - 1 >= 0 && grid[x][y - 1] === 0) len ++;
        if(y + 1 < col && grid[x][y + 1] === 0 ) len ++;
    }

    for(let i = 0; i < row; i ++) {
        for(let j = 0; j < col; j ++) {
            if(grid[i][j] == 1) {
                find(i, j)
            }
        }
    }
    return len;
};
```