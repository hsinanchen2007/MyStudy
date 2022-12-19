### 解题思路
此处撰写解题思路
n个```1 * 1 * 1```的立方体堆在一起的表面积是4n + 2
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let res = 0
    const len = grid.length
    for (let i = 0; i < len; i ++) {
        for (let j = 0; j < len; j ++) {
            let area
            const num = grid[i][j]
            if (grid[i][j] === 0) {
                area = 0
            } else {
                // n个1*1*1的立方体堆在一起的表面积
                area = 4 * num + 2
            }
            // 当前位置的上下左右
            const neighbor = [[i - 1, j], [i, j - 1], [i + 1, j], [i, j + 1]]
            for (let k = 0; k < 4; k ++) {
                const x = neighbor[k][0]
                const y = neighbor[k][1]
                if (grid[x] && grid[x][y]) {
                    // 取当前立方体和邻居中矮的那个，面积减去该立方体一个面的面积
                    const min = Math.min(num, grid[x][y])
                    area -= min
                }
            }
            res += area
        }
    }
    return res
};

```