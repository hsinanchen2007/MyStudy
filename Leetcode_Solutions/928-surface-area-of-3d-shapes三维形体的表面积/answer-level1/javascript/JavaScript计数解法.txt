解题思路：本题是在一个三维空间中的二维平面上叠放立方体。单个立方体的表面积为6，每有一个面重叠表面积就-2。我的思路就是循环遍历，找到总的立方体个数count和重叠的面积x，最后相减得到结果。
js代码：
```
var surfaceArea = function(grid) {
    let count = 0;
    let x = 0;
    for (let i=0;i<grid.length;i++){
        for (let j=0;j<grid[i].length;j++){
            count+=grid[i][j];
            if (grid[i][j] !==0){//如果这个点的值不为零计算这个点在z方向即垂直方向上的重叠面积
                x+=(grid[i][j]-1)*2;
            }
            if (i !==0){//如果i!=0计算这个点在i或者说x方向上的重叠面积
                x+=(Math.min(grid[i-1][j],grid[i][j])*2);
            }
            if (j !==0){//如果j!=0计算这个点在j或者说y方向上的重叠面积
                x+=(Math.min(grid[i][j-1],grid[i][j])*2);
            }
        }
    }
    return count*6-x
};
```
