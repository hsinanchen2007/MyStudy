### 解题思路
见注释

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
            const m = grid.length
            const n = grid[0].length
            // 记录腐烂橘子坐标
            const queue = []
            // 记录有多少新鲜橘子
            let fresh = 0
            // 记录时间
            let time = 0
            for (let i = 0; i < m; i++) {
                for (let j = 0; j < n; j++) {
                    if (grid[i][j] === 2) {
                        queue.push([i, j])
                    } else if (grid[i][j] === 1) {
                        fresh ++
                    }
                }
            }
            // 记录一个位置上下左右位置坐标偏移
            const del = [[0, 1], [0, -1], [-1, 0], [1, 0]]
            while (queue.length && fresh) {
                const len = queue.length
                for (let i = 0; i < len; i++) {
                    const item = queue.shift()
                    for (let j = 0; j < 4; j++) {
                        const x = item[0] + del[j][0]
                        const y = item[1] + del[j][1]
                        if (shouldInfect(grid, x, y)) {
                            fresh --
                            queue.push([x, y])
                            grid[x][y] = 2
                        }
                    }
                }
                time ++
            }
            return fresh === 0 ? time : -1
        };

        // 判断一个橘子是不是会被感染
        function shouldInfect (grid, x, y) {
            return grid[x] && grid[x][y] && grid[x][y] === 1
        }
```