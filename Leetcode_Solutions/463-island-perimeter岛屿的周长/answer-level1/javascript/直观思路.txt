### 解题思路
循环 
判断当前格子是否是陆地，若是陆地判断四周是否是海洋/边界，是则周长+1 
最后返回周长

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    let sum=0;
    for(let i=0;i<grid.length;i++) {
        for(let j=0;j<grid[i].length;j++) {
            if(grid[i][j] == 1) {
                if(i == 0) {
                    sum++;
                } else {
                    if (grid[i-1][j] != 1) {
                        sum++;
                    }
                }
                if(i == grid.length-1) {
                    sum++;
                } else {
                    if (grid[i+1][j] != 1) {
                        sum++;
                    }
                }
                if(j == 0) {
                    sum++;
                } else {
                    if (grid[i][j-1] != 1) {
                        sum++;
                    }
                }
                if(j == grid[i].length-1) {
                    sum++;
                } else {
                    if (grid[i][j+1] != 1) {
                        sum++;
                    }
                }
            }
        }
    }
    return sum;
};
```