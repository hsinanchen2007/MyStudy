首先，一个柱体一个柱体的看，每个柱体是由：2个底面（上表面/下表面）+ 所有的正方体都贡献了4个侧表面积。
然后，把柱体贴合在一起之后，我们需要把贴合的表面积给减掉，两个柱体贴合的表面积就是 两个柱体高的最小值*2。


```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let area = 0;
    const len = grid.length;
    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len; j++) {
            const val = grid[i][j];
            if (val) {
                area += (val << 2) + 2;
                if (i > 0) {
                    area -= Math.min(grid[i - 1][j], val) << 1;
                }
                if (j > 0) {
                    area -= Math.min(grid[i][j - 1], val) << 1;
                }
            }
        }
    }
    return area;
};
```