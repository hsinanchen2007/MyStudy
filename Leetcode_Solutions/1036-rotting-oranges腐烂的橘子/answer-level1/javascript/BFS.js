### 解题思路
典型的深度优先搜索。

我们先遍历一遍，将所有腐烂的橘子的位置放入队列 {x: 腐烂橘子的横坐标, y: 腐烂橘子的纵坐标, min: 该橘子腐烂需要的时间}，并给新鲜的橘子计数。

当队列中有元素时，取出队列中的第一个元素 current，检查 current 的上下左右四个位置是否有新鲜的橘子，如果有的话：
将新鲜橘子的位置入队 {x: 腐烂橘子的横坐标, y: 腐烂橘子的纵坐标, min: current + 1}，并且更新当前的最大时间。

当队列中没有元素时，检查 cnt 是否为 0，若不为零则返回 -1， 否则返回当前的最大时间。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const m = grid.length, n = grid[0].length;
    const queue = new Array(), offset = [{x: -1, y: 0}, {x: 1, y: 0}, {x: 0, y: -1}, {x: 0, y: 1}];
    let cnt = 0, res = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                ++cnt;
                continue;
            }
            if (grid[i][j] === 2) {
                queue.push({x: i, y: j, min: 0});
            }
        }
    }
    while(queue.length) {
        const current = queue.shift();
        for (let i = 0; i < 4; ++i) {
            if ((offset[i].x+current.x >= 0) 
            && (offset[i].y+current.y >= 0) 
            && (offset[i].x+current.x < m) 
            && (offset[i].y+current.y < n) 
            && grid[offset[i].x+current.x][offset[i].y+current.y] === 1) {
                grid[offset[i].x+current.x][offset[i].y+current.y] = 2;
                --cnt;
                queue.push({x: offset[i].x+current.x, y: offset[i].y+current.y, min: current.min + 1});
                res = Math.max(res, current.min + 1);
            }
        }
    }
    return cnt ? -1 : res;
};
```

### 复杂度
- 时间复杂度 O(MN)
- 空间复杂度 O(MN)