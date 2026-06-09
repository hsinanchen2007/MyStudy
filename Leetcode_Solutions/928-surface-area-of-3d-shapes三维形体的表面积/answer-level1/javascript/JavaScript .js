### 解题思路
求每一个单元格的表面积，然后累加；
每一个单元格表面积 = 所有立方体表面积 - 左右上下及内部各个立方体相连部分的面积。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    var res = 0;
    for(var i = 0; i < grid.length; i++){
        for(var j = 0; j < grid[i].length;j++){
            //当前为0，继续下一个
            if(!grid[i][j]) continue;
            //当前各个立方体表面积和
            let all = grid[i][j] * 6;
            //内部相接触面积
            let inner = (grid[i][j] - 1) * 2;
            //与上层立方体接触面积
            let up = i > 0 ? Math.min(grid[i-1][j],grid[i][j]) : 0;
            //与下层立方体接触面积
            let down = i < grid.length - 1 ? Math.min(grid[i+1][j],grid[i][j]) : 0;
            //与左侧立方体接触面积
            let left = j > 0 ? Math.min(grid[i][j-1],grid[i][j]) : 0;
            //与右侧立方体接触面积
            let right = j < grid[i].length - 1 ? Math.min(grid[i][j+1],grid[i][j]) : 0;
            //累加到最终和
            res +=(all - inner - up - down - left - right);
        }
    }
    return res;
}
```