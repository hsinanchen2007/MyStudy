dfs 递归
首先设定 4 个方向，碰到 0 就退出递归
如果为 1，则继续向四个方向递归，并把四个方向得到的结果加起来，和最终的结果比大小

```
var dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
var maxAreaOfIsland = function (grid) {
    var res = 0;
    for (var i = 0; i < grid.length; i++) {
        for (var j = 0; j < grid[i].length; j++) {
            if (grid[i][j] == 1) {
                res = Math.max(res, dfs(grid, i, j));
            }
        }
    }
    return res;
};
function dfs(arr, x, y) {
    if (x < 0 || y < 0 || x >= arr.length || y >= arr[x].length || arr[x][y] === 0) return 0;
    arr[x][y] = 0;
    var sum = 1;
    for (var i = 0; i < dir.length; i++) {
        sum += dfs(arr, x + dir[i][0], y + dir[i][1])
    }
    return sum;
}

```
