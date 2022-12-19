### 解题思路
1. 先计算正方体总表面积 S
2. 计算Z轴（上下）覆盖面积 s1
3. 计算右侧，后侧覆盖面积 s2
4. 三维体表面积： S - ( s1 + s2 )
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
/**
 *       i=> 0    1    2
 *  j↓  0 [ x → x → x ]
 *         [ ↓   ↓   ↓]
 *      1  [ x → x → x ]
 *         [ ↓   ↓   ↓]
 *      2  [ x → x → x ]
 */
var surfaceArea = function(grid) {
    let S = 0, // 总表面积  // S=6×a×a
        cover = 0 //覆盖面积 
    for( let i=0; i<grid.length; i++){
        for( let j=0; j<grid[i].length; j++ ){
            S += grid[i][j] * 6
            // 计算上下重叠 
            if( grid[i][j] ) cover += ( grid[i][j] - 1 ) * 2
            
            // 如图：  计算 右侧 、下侧（后边）。因为是计算覆盖面积，取相邻正方体最矮的高度（最小值）
            // 右侧（同一行 i不变，j + 1）
            if( grid[i][j+1] )  cover += Math.min( grid[i][j+1], grid[i][j] ) * 2

            // 下侧（同一列 i + 1, j不变）
            if( grid[i+1] && grid[i+1][j] )  cover += Math.min( grid[i+1][j], grid[i][j] ) * 2
        }
    }
    return S -cover
};
```