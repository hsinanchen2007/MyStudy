### 解题思路
见注释

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    if(grid.length === 0 || grid[0].length === 0) return 0;
    let rows = grid.length;
    let cols = grid[0].length;
    let area = 0;
    let top=0,right=0,bottom=0,left=0;
    for(let i=0;i<rows;i++){
        for(let j=0;j<cols;j++){
            let n = grid[i][j]; // n表示[i,j]上有几个小立方体 
            if(n !== 0){
                // 1个立方体的表面积：1*6=6
                // 2个立方体的表面积：2*6 - 1*2 = 10
                // 3个立方体的表面积：3*6 - 2*2 = 14
                // n个立方体的表面积：n*6 - (n-1)*2 = 4*n+2
                area += 4 * n + 2; // 不考虑[i,j]周围的小立方体的情况下计算[i,j]上小立方体的表面积
            } else {
                continue; // [i,j]上没有小立方体的情况下退出当前循环，继续下一次循环
            }

            // 统计[i,j]上右下左四个方向小立方体的个数
            if(i>0) {
                top = grid[i-1][j]; 
            }
            if(i<rows-1) {
                bottom = grid[i+1][j];
            }
            if(j>0){
                left = grid[i][j-1];
            }
            if(j<cols-1) {
                right = grid[i][j+1];
            }
            
            // 以[i,j]上方的小立方体个数top为例子
            // 如果top>=n，那么重叠面积为n，此时表面积应该减去n
            // 如果top<n,那么重叠面积为top，此时表面积应该减去top
            // 重叠的面为两面，这里不减去2的原因是遍历[i-1][j]的时候已经减过一次了
            top >= n ? area -= n:area-=top;
            bottom >= n ? area -= n: area -= bottom;
            left >= n ? area -= n:area-=left;
            right >= n ? area -= n:area-=right;

            // [i,j]实际表面积计算好之后，四个方向上的小立方体个数需要重新初始化为0
            // 否则当i或者j不满足if条件时，top、bottom、left、right本应该为0，
            // 在没有重新初始化的情况下会保持上一次的值，给计算带来影响
            top=0;right=0;bottom=0;left=0;
        }
    }

    return area;
};
```