### 解题思路
深度优先遍历 递归

### 代码

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const gLen = grid.length
    if (!gLen) {
        return 0
    }
    const hLen = grid[0].length
    // 存储当前所选元素在平面内上下左右四个方向元素
    const d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    // 维护递归过程中，平面中元素的使用状态，每个只能使用一次
    const used = []
    // 保存岛屿数量
    let count = 0
    // 判断所选元素是否在二维平面内
    const inArea = function (x, y) {
        return x >=0 && x < grid.length && y >=0 && y < grid[0].length
    }
    // 递归函数，深度优先遍历，从grid[i][j]开始移动，将所有链接的陆地标记为访问过
    const dfs = function (grid, i, j) {
        used[i][j] = true
        for (let k = 0; k < 4; k++) {
            const newX = i + d[k][0]
            const newY = j + d[k][1]
            inArea(newX, newY) && !used[newX][newY] && grid[newX][newY] == 1 && dfs(grid, newX, newY)
        }
        return
    }
    for (let i = 0; i < gLen; i++) {
        used.push(new Array(hLen).fill(false))
    }
    for (let i = 0; i < gLen; i++) {
        for (let j = 0; j < hLen; j++) {
            if (!used[i][j] && grid[i][j] == 1) {
                count ++
                dfs(grid, i, j)
            }
        }
    }
    return count
};
```