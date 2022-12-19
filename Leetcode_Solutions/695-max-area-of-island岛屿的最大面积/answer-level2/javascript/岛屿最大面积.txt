用递归的方法深度优先搜索计算岛屿面积。遍历整个矩阵求最大面积。```
var maxAreaOfIsland = function(grid) {
    let maxArea = 0;
    for(let i=0; i< grid.length; i++){
        for(let j=0; j<grid[0].length; j++){
            if(grid[i][j] != 0){
                maxArea = Math.max(maxArea, areaOfIsland(grid, i, j));
            }
        }
    }
    return maxArea;
};

function areaOfIsland(grid,row,col){
    if(row>=0 && col>=0 && row<grid.length && col<grid[0].length && grid[row][col]==1){
        grid[row][col]=0;
        return 1+areaOfIsland(grid,row+1,col)+areaOfIsland(grid,row-1,col)+areaOfIsland(grid,row,col+1)+areaOfIsland(grid,row,col-1)
    }
    return 0;
}
```
