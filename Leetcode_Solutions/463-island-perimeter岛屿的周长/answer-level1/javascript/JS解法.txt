### 解题思路
周长可以理解为 陆地乘以4 减去重合边乘以2，这样可以减少很多情况出现；
横竖轴上各往一个方向进行判断，避免重复计算重合边。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    let count=0;
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
            if(grid[i][j]===1){
                count+=4
                if (i>0&&grid[i-1][j]===1) {
                    count-=2
                }
                if (j>0&&grid[i][j-1]===1) {
                    count-=2;
                }
            }
        }
    }
    return count
};

```