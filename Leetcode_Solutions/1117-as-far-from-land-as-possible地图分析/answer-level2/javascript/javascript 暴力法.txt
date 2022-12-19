### 解题思路
循环遍历分开陆地和海洋，最终结果就是每个海洋和陆地之间最短距离的最大值

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    const m = grid.length
    const n = grid[0].length
    const land = []
    const sea = []
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                land.push([i, j])
            } else {
                sea.push([i, j])
            }
        }
    }
    const sLen = sea.length
    const lLen = land.length
    let max = -Infinity
    if (!sLen || !lLen) {
        return -1
    }
    for (let i = 0; i < sLen; i++) {
        let min = Infinity
        const seaX = sea[i][0]
        const seaY = sea[i][1]
        for (let j = 0; j < lLen; j++) {
            const landX = land[j][0]
            const landY = land[j][1]
            min = Math.min(min, Math.abs(seaX - landX) + Math.abs(seaY - landY))
        }
        max = Math.max(max, min)
    }
    return max
};
```