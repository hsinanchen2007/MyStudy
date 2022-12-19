### 解题思路
思路写在下面注释里

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    const gLen = grid.length
    const len = grid[0].length
    // 统计边长
    let perimeter = 0
    for (let i = 0; i < gLen; i++) {
        for (let j = 0; j < len; j++) {
            // 如果当前格子是陆地
            if (grid[i][j] === 1) {
                // 初始化一个数组来辅助检测当前格子上下左右格子是否越界
                const mesh = [[0, 1], [0, -1], [1, 0], [-1, 0]]
                let count = 4
                for (let k = 0; k < 4; k++) {
                    // 如果当前陆地紧挨的格子没有越界，也是陆地，边长减1
                    if (inArea(i + mesh[k][0], j + mesh[k][1], gLen, len) && grid[i + mesh[k][0]][j + mesh[k][1]] === 1) {
                        count --
                    }
                }
                perimeter += count
            }
        }
    }
    return perimeter
};

// 判断当前格子是否越界
function inArea (x, y, limitX, limitY) {
    return x >= 0 && x < limitX && y >= 0 && y < limitY
}
```