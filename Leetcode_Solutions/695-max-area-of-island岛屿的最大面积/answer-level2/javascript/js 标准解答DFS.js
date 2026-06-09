```
var maxAreaOfIsland = function(grid) {
    const row = grid.length;
    const col = grid[0].length;
    let max = grid[0][0];
    function getArea(grid, i, j) {
        if(i < 0 || j < 0 || i >= row || j >= col || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return getArea(grid, i - 1, j) + getArea(grid, i + 1, j)
            + getArea(grid, i, j - 1) + getArea(grid, i, j + 1) + 1;
    }
    for(let i = 0; i < row; i++) {
        for(let j = 0; j < col; j++) {
            if(grid[i][j]){
                max = Math.max(max,getArea(grid,i,j));
            }
        }
    }
    return max;
};
```
