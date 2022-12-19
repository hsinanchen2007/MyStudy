### 解题思路
深度优先遍历，每次dfs就是把当前点变成0

### 代码

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    function dfs(x, y) {
        grid[x][y] = 0
        if(grid[x - 1] && grid[x - 1][y] == 1) dfs(x-1, y)
        if(grid[x + 1] && grid[x + 1][y] == 1) dfs(x+1, y)
        if(grid[x][y - 1] == 1) dfs(x, y - 1)
        if(grid[x][y + 1] == 1) dfs(x, y + 1)
    }
    let count = 0
    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j< grid[0].length; j++) {
            if(grid[i][j] == 1) {
                dfs(i, j)
                count++
            }
        }
    }
    return count
};
```