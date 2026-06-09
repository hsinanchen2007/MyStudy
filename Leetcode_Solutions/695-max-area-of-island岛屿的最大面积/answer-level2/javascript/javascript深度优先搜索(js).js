深度优先搜索

算法

我们想知道网格中每个连通形状的面积，然后取最大值。

如果我们在一个土地上，以 4 个方向探索与之相连的每一个土地（以及与这些土地相连的土地），那么探索过的土地总数将是该连通形状的面积。

为了确保每个土地访问不超过一次，我们每次经过一块土地时，将这块土地的值置为 0。这样我们就不会多次访问同一土地。


```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let ans = 0;
    const len1 = grid.length;
    const len2 = grid[0].length;
    for (let i = 0; i < len1; i++) {
        for (let j = 0; j < len2; j++) {
            ans = Math.max(ans, dfs(grid, i, j));
        }
    }
    return ans;
};

function dfs(grid, i, j) {
    if (i < 0 || j < 0 || i > grid.length - 1 || j > grid[0].length - 1 || !grid[i][j]) {
        return 0;
    }
    grid[i][j] = 0;
    const di = [1, -1, 0, 0];
    const dj = [0, 0, 1, -1];
    let ans = 1;
    for (let k = 0; k < 4; k++) {
        ans += dfs(grid, i + di[k], j + dj[k]);
    }
    return ans;
}
```