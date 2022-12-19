### 解题思路
![image.png](https://pic.leetcode-cn.com/c89965da13bd8e566a4410c8ceac6ef2f3434b1aafba237446da012cb6c12924-image.png)

与200题类似，用队列来搜寻一个岛。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    if (grid.length === 0) return 0;

    let height = grid.length,
        width = grid[0].length,
        que = [],
        hasIsland = false,
        size = 0,
        maxSize = 0;

    while (true) {
        size = 0;
        hasIsland = false;
        findIsland: {
            for (let i = 0; i < height; i++) {
                for (let j = 0; j < width; j++) {
                    if (grid[i][j] === 1) {
                        hasIsland = true;
                        que.push([i, j]);
                        grid[i][j] = 0;

                        if (j <= width - 2 && grid[i][j + 1] === 0 || j === width - 1) {
                            break findIsland;
                        }
                    }
                }
            }
        }
        if (!hasIsland) break;
        while (que.length) {
            let len = que.length;
            size += len;
            for (let i = 0; i < len; i++) {
                const pos = que.shift();
                const x = pos[0];
                const y = pos[1];
                if (x > 0 && grid[x - 1][y] === 1) {
                    que.push([x - 1, y]);
                    grid[x - 1][y] = 0;
                }
                if (x < height - 1 && grid[x + 1][y] === 1) {
                    que.push([x + 1, y]);
                    grid[x + 1][y] = 0;
                }
                if (y > 0 && grid[x][y - 1] === 1) {
                    que.push([x, y - 1]);
                    grid[x][y - 1] = 0;
                }
                if (y < width - 1 && grid[x][y + 1] === 1) {
                    que.push([x, y + 1]);
                    grid[x][y + 1] = 0;
                }
            }
        }
        maxSize = Math.max(maxSize, size);
    }
    return maxSize;
};
```