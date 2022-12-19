
每次取出子数组最后一个*splice(xL,1)*，然后将前一个数组的最后一个，插入第一个位置*unshift(grid[y-1][xL])*
```
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {
    xL=grid[0].length-1; //我是有几列
    yL=grid.length-1; //我是行

    for(let q=0;q<k;q++){
        let lastItem = grid[yL][xL];
        for(let y=yL;y>=1;y--){
          grid[y].splice(xL,1);
        grid[y].unshift(grid[y-1][xL])
        }
         grid[0].splice(xL,1);
        grid[0].unshift(lastItem)
    }
    return grid;
};
```
