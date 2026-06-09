```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let count = 0; // 记录个数
    let len = grid.length;
    let zlen = 0; //各个方向重叠的个数
    let xlen = 0;
    let ylen = 0;
    for(let i=0;i<len;i++){
        for(let j=0;j< (len -1);j++){
            if(grid[i][j] > 0){
                zlen += (grid[i][j] -1) *2;    // 纵向的重叠面
            }
            xlen += Math.min(grid[i][j],grid[i][j+1]) * 2; // 分别去记录x、y方向的重叠面
            ylen += Math.min(grid[j][i],grid[j+1][i]) * 2;
            count += grid[i][j];
        }
        // 记录每行的最后一项
        if(grid[i][len - 1] > 0){
            zlen += (grid[i][len - 1] - 1) * 2;
        }
        count += grid[i][len - 1];
    }
    return count * 6 - zlen - xlen - ylen;   // 表面积=总的个数*6 - 各个方向重叠的面

};
```
