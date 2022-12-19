### 解题思路

// 首先，先看一个网格上面的情况：

        // 一个网格里面一个立方体则S为6，然后每加一个立方体，S加4

        // 算出该立方体的面积之后，判断其上下左右是否有立方体，若有，则减去其方向上的表面积

        // 即S减去四个方向上的立方体总和(如果该方向的立方体比[i,j]大，则只需减去[i]][j]该方向的表面积，这也就是我用Math.min()的原因)，此时的S才是整个形体在[i,j]位置上的表面积

        // 然后按照此方法计算出所有网格的S，总和即整个形体的S

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let xLen = grid.length;
    let yLen = grid[0].length;
    let S = 0;
    for(let x = 0; x < xLen; x ++) {
        for(let y = 0; y < yLen; y ++) {
            let tempS = (grid[x][y] !== 0) ? grid[x][y] * 4 + 2 : 0;
            tempS -= (x > 0) ? Math.min(grid[x - 1][y], grid[x][y]) : 0;
            tempS -= (x < xLen - 1) ? Math.min(grid[x + 1][y], grid[x][y]) : 0;
            tempS -= (y > 0) ? Math.min(grid[x][y - 1], grid[x][y]) : 0;
            tempS -= (y < yLen - 1) ? Math.min(grid[x][y + 1], grid[x][y]) : 0;
            S += tempS; 
        }
    }
    return S;
};
```