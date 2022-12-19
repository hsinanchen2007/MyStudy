### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    if (grid.length === 1 && grid[0].length === 1) {
        return grid[0][0] !== 1 ? 0 : -1;
    }
    let queue = [], count = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === 2) {
                queue.push([i, j]);
            } else if (grid[i][j] === 1) {
                count++;
            }
        }
    }
    let level = 0;
    while (queue.length && count) {
        level++;
        let size = queue.length;
        for (let i = 0; i < size; i++) {
            let item = queue.shift();
            let y = item[0], x = item[1];
            if (y - 1 >= 0 && grid[y - 1][x] === 1 ) {
                grid[y - 1][x] = 2;
                count--;
                queue.push([y - 1, x]);
            }
            if (y + 1 < grid.length && grid[y + 1][x] === 1 ) {
                grid[y + 1][x] = 2;
                count--;
                queue.push([y + 1, x]);
            }
            if (x - 1 >= 0 && grid[y][x - 1] === 1 ) {
                grid[y][x - 1] = 2;
                count--;
                queue.push([y, x - 1]);
            }
            if (x + 1 < grid[0].length && grid[y][x + 1] === 1 ) {
                grid[y][x + 1] = 2;
                count--;
                queue.push([y, x + 1]);
            }
        }
    }
    return count ? -1 : level;
};
```