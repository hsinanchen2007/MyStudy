### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let result = 0;
    const dfs = (i, j) => {
        if (i < 0 || j <0 || i >= grid.length || j >= grid[0].length) {
            return 0;
        }
        let area = grid[i][j];
        if (!area) {
            return 0;
        }
        grid[i][j] = 0;
        let addInfo = [[0,-1],[0,1],[-1,0],[1,0]];
        for (let k=0; k<4;k++) {
            area += dfs(i+addInfo[k][0], j+addInfo[k][1]);
        }
        return area;
    }
    for (let i = 0; i < grid.length; i++) {
        let row = grid[i];
        for (let j =0; j < row.length; j++) {
            if (grid[i][j]) {
                result = Math.max(result, dfs(i,j));
            }
        }
    }
    return  result;
};
```