如果使用暴力方法，执行时间是个问题。

```js
const wallsAndGates = function(rooms) {
    if (rooms.length === 0 || rooms[0].length ===0){
        return;
    }
    const m = rooms.length;
    const n = rooms[0].length;
    function bfs (i, j, step) {
        // 边界条件
        if (i < 0 || i >= m 
            || j < 0 || j >= n
            || rooms[i][j] < step ) {
            return;
        }
        // 上下左右
        rooms[i][j] = step;
        bfs(i-1, j, step + 1);
        bfs(i+1, j, step + 1);
        bfs(i, j-1, step + 1);
        bfs(i, j+1, step + 1);
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (rooms[i][j] === 0) {
                bfs(i, j, 0)
            }
        }
    }
};
```