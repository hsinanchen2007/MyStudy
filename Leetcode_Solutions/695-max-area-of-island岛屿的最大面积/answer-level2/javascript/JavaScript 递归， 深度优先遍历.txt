### 解题思路
深度优先搜索

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    const gLen = grid.length
    if (!gLen) {
        return 0
    }
    const hLen = grid[0].length
    // 存储当前所选元素在平面内上下左右四个方向元素
    const d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    // 维护递归过程中，平面中元素的使用状态，每个只能使用一次
    const used = []
    // 保存岛屿最大面积
    let max = 0
    let count = 0
    // 判断所选元素是否在二维平面内
    const inArea = function (x, y) {
        return x >=0 && x < grid.length && y >=0 && y < grid[0].length
    }
    // 递归函数，深度优先遍历，从grid[i][j]开始移动，将所有链接的陆地标记为访问过
    const dfs = function (grid, i, j) {
        used[i][j] = true
        count ++
        for (let k = 0; k < 4; k++) {
            const newX = i + d[k][0]
            const newY = j + d[k][1]
            if (inArea(newX, newY) && !used[newX][newY] && grid[newX][newY] == 1) {
                dfs(grid, newX, newY)
            }
        }
    }
    for (let i = 0; i < gLen; i++) {
        used.push(new Array(hLen).fill(false))
    }
    for (let i = 0; i < gLen; i++) {
        for (let j = 0; j < hLen; j++) {
            if (!used[i][j] && grid[i][j] == 1) {
                dfs(grid, i, j)
                max = Math.max(max, count)
                count = 0
            }
        }
    }
    return max
};
```