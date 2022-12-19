### 解题思路
遍历grid 当等于1的时候，调用函数area(将下标传过去)

主要是就是函数area的实现， 依次找上右下左，注意下标越界问题，函数退出条件，

还要注意要将遍历了的1置为0.

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
     let max = 0

  const area = function(i,j) {
    if (grid[i][j] == 0) return 0
    let count = 1
    grid[i][j] = 0
    if (i+1 < grid.length && grid[i+1][j] == 1)  //下
      {
        // console.log("下")
        // count += 1
        count += area(i+1,j)
        grid[i+1][j] = 0
      }
    if (i-1 >= 0 && grid[i-1][j] == 1)   //上
      {
        // console.log("上")
        // count += 1
        
        count += area(i-1,j)
        grid[i-1][j] = 0
      }
    if (j+1 < grid[i].length && grid[i][j+1] == 1)    //右
      {
        // console.log("右")
        // count += 1
       
        count += area(i,j+1)
        grid[i][j+1] = 0
      }
    if (j-1 >= 0 && grid[i][j-1] == 1)    //左
      {
        // console.log("左")
        // count += 1
        
        count += area(i,j-1)
        grid[i][j-1] = 0
      }
     
    return count
  }
  

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] == 1) {
        max = Math.max(max,area(i,j))
      }
    }
  }

  return max
};







```