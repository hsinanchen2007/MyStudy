### 解题思路
这道题用到DFS（深度优先搜索）的概念；
首先对矩阵各点进行循环，遇到1则进行搜索方法；
搜索方法：先判断是否为合法坐标，再判断是否为1，遇到1记录一次，当前点置零（避免重复计算）对当前坐标的上下左右进行判断搜索判断（递归）返回值是1的次数，最终合计值是1的点的个数。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let count=0,x=grid[0].length,y=grid.length;
    for(let i=0;i<y;i++){
        for(let j=0;j<x;j++){
            if(grid[i][j]===1) count=Math.max(count,areaOfIsland(grid,i,j,y,x))
        }
    }
    return count
};

var areaOfIsland = (grid,i,j,y,x) =>{
    if(i>=y||i<0||j>=x||j<0||grid[i][j]===0) return 0
    let num=1;
    grid[i][j]=0;
    num+=areaOfIsland(grid,i+1,j,y,x);
    num+=areaOfIsland(grid,i-1,j,y,x);
    num+=areaOfIsland(grid,i,j+1,y,x);
    num+=areaOfIsland(grid,i,j-1,y,x);
    return num
};
```