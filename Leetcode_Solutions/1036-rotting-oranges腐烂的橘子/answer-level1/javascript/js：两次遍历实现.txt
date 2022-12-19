# 比较简单粗暴的方法：
遍历然后每次把2周围的传染，直到不再出现传染时，再遍历一次检查是否还存在1。这种做法需要几分钟就要遍历几次，时间复杂度较高。
# 稍微优化一下遍历次数
1、遍历一次，当遇到2时则一直传染下去（每次传染时间+1）直到不再发现周围有1，即rotAround方法；
2、再遍历一次，如果还有1，说明有橘子无法传染返回-1，否则就找到grid中的最大值即可


```
var orangesRotting = function(grid) {
    let res = 0
    for (let y = 0; y < grid.length; y++) {
        for (let x = 0; x < grid[y].length; x++) {
            if (grid[y][x] === 2) {
                rotAround(x, y)
            }
        }
    }
    for (let y = 0; y < grid.length; y++) {
            for (let x = 0; x < grid[y].length; x++) {
                if (grid[y][x] === 1) {
                    return -1
                }
                res = Math.max(res, grid[y][x] - 2)
            }
        }
    return res

    function rotAround(x, y) {
        let time = grid[y][x] + 1
        if (grid[y - 1]) {
            rotSelf(x, y - 1, time)
        }
        if (grid[y + 1]) {
            rotSelf(x, y + 1, time)
        }
        rotSelf(x - 1, y, time)
        rotSelf(x + 1, y, time)
    }
    function rotSelf(x, y, time) {
        if (grid[y][x] === 1) {
            grid[y][x] = time
            rotAround(x, y)
        } else if (grid[y][x] > 2 && grid[y][x] > time) {
            grid[y][x] = time
            rotAround(x, y)
        }
    }
};
```
