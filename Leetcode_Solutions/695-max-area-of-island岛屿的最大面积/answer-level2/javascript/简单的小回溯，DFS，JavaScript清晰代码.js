### 解题思路
首先找到第一个为1的位置，然后调用函数计算包含该位置的岛屿的面积，计算的同时将算过的地方都变为0，计算完一块岛屿面积之后与最大岛屿面积比较，若比它大则替换掉，依次循环即可。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    const xLen = grid.length;
    if(!xLen) return 0;
    const yLen = grid[0].length;
    let maxArea = 0;//最大岛屿的面积
    let area;//每个岛屿的面积
    for(let x = 0; x < xLen; x ++) {
        for(let y = 0; y < yLen; y ++) {
            if(grid[x][y] === 1) {
                area = 0;
                computeArea(x, y);
                maxArea = Math.max(maxArea, area);
            }
        }
    }
    return maxArea;

    function computeArea(x, y) {//计算包含xy位置的岛屿的面积
        if(grid[x][y] === 1){
            area ++;
            grid[x][y] = 0;
            x - 1 >= 0 && grid[x - 1][y] && computeArea(x - 1, y);//top
            y + 1 <= yLen - 1 && grid[x][y + 1] && computeArea(x, y + 1);//right
            x + 1 <= xLen - 1 && grid[x + 1][y] && computeArea(x + 1, y);//bottom
            y - 1 >= 0 && grid[x][y - 1] && computeArea(x, y - 1);//left
        }
    }
};
```