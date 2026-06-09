### 解题思路
和隔壁重合的面积为高度矮的那叠的面积

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let number = 0

    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[i].length; j++){
            let one = 0
            if(grid[i][j] == 0){
                continue
            }
            
            one = grid[i][j] ==1 ?6 :
                grid[i][j] == 2?10:
                    grid[i][j]>2? (grid[i][j]-2)*4+10 :0
            const top = j+1<grid[0].length?Math.min(grid[i][j+1],grid[i][j]):0;
            const bot = j-1>=0?Math.min(grid[i][j-1],grid[i][j]):0;
            const left = i-1>=0?Math.min(grid[i][j],grid[i-1][j]):0;
            const right = i+1<grid.length?Math.min(grid[i][j],grid[i+1][j]):0;

            one = one - top - bot - left -right

            number += one
        }
    }

    return number
};
```