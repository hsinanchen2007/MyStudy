### 解题思路
![image.png](https://pic.leetcode-cn.com/c456fa3817247a86720bf189130b410aa0265a0d291f56e15a856bfd95b813d0-image.png)

逐行找，找到每行连着的1，坐标放入队列，然后处理队列，出队列1个，检查其周围的四个，也是1的话就进队列，队列空了，就检索完了一个岛。再下一轮的逐行找1找下一个岛。

每次找到了1，就改为0，所谓的“沉岛”。

### 代码

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
    if (grid.length === 0) return 0;

    let height = grid.length,
        width = grid[0].length,
        que = [],
        hasIsland = false,
        num = 0;

    while (true) {
        hasIsland = false;
        findIsland: {
            for (let i = 0; i < height; i++) {
                for (let j = 0; j < width; j++) {
                    if (grid[i][j] === "1") {
                        hasIsland = true;
                        que.push([i, j]);
                        grid[i][j] = "0";
                        if (j <= width - 2 && grid[i][j + 1] === "0" || j === width - 1) {
                            break findIsland;
                        }
                    }
                }
            }
        }
        if (!hasIsland) break;
        num++;
        while (que.length) {
            let len = que.length;
            for (let i = 0; i < len; i++) {
                const pos = que.shift();
                const x = pos[0];
                const y = pos[1];
                if (x > 0 && grid[x - 1][y] === "1") {
                    que.push([x - 1, y]);
                    grid[x - 1][y] = "0";
                }
                if (x < height - 1 && grid[x + 1][y] === "1") {
                    que.push([x + 1, y]);
                    grid[x + 1][y] = "0";
                }
                if (y > 0 && grid[x][y - 1] === "1") {
                    que.push([x, y - 1]);
                    grid[x][y - 1] = "0";
                }
                if (y < width - 1 && grid[x][y + 1] === "1") {
                    que.push([x, y + 1]);
                    grid[x][y + 1] = "0";
                }
            }
        }
    }
    return num;
};
```