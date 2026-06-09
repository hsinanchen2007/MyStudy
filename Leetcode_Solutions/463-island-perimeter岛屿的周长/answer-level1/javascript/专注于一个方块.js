### 解题思路

看方块的四面, 看它四面是否有1 没有1就算周长.

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    let nums = 0
    for(let i = 0; i< grid.length; i++){
      let arr = grid[i]
      arr.forEach((t,j) => {
        if(t === 1){
          if(!arr[j-1] || arr[j-1] && arr[j-1] === 0)  ++nums    // left     ( && 优先级大于 || )
          if(!arr[j+1] || arr[j+1] && arr[j+1] === 0)  ++nums    // right

          if(!grid[i-1] || grid[i-1] && grid[i-1][j] === 0)  ++nums   // top
          if(!grid[i+1] || grid[i+1] && grid[i+1][j] === 0)  ++nums   // bottom
        }
      })
    }
    return nums
};
```