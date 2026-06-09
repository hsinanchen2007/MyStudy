```
/**
 * @param {number[][]} grid
 * @return {number}
 */

// 1:某个位置的正方形表面积为 grid[i][j] * 4 + 2
// 2:处理重叠面积情况，相邻时，取最小的高度 * 2 即为重叠的面积，
//   遍历顺序为 从左到右从上到下，因此要考虑上方、左侧的重叠面积情况
// 3:题目中说明为 N*N 所以，数组必然为 N*N 维

var surfaceArea = function(grid) {
    let n = grid.length;
    let allArea = 0;
    for (let i = 0; i < n; i ++) {
        for (let j = 0; j < n; j ++) {
            if (grid[i][j] === 0) {
                continue;
            }
            // 计算当前位置的正方形表面积
            allArea += grid[i][j] * 4 + 2;
            // 去除重叠面积
            // 上方
            if (i - 1 >= 0) {
                allArea -= Math.min(grid[i-1][j], grid[i][j]) * 2
            }
            // 左侧
            if (j - 1 >= 0) {
                allArea -= Math.min(grid[i][j], grid[i][j-1]) * 2
            }
        }
    }
    return allArea;
};
```