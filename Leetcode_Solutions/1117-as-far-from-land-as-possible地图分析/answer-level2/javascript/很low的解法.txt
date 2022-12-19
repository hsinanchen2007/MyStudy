### 解题思路
用两个数组分别存储陆地和海洋的坐标，然后进行遍历，更新最大值

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
  let continent = []
  let ocean = []
  let n = grid.length
  for(let i = 0;i<n;i++) {
      for(let j = 0;j<n;j++) {
          if(grid[i][j] === 0) {
              ocean.push({
                  x: i,
                  y:j
              })
          }else {
              continent.push({
                  x: i,
                  y:j
              })
          }
      }
  }
  if(continent.length===n**2||ocean.length===n**2) return -1
  let max = 0
  for(let i = 0;i<ocean.length;i++) {
      let min = 1000000000
      for(let  j = 0;j<continent.length;j++) {
          let tmp = Math.abs(continent[j].x-ocean[i].x) +Math.abs(continent[j].y-ocean[i].y)
          min = Math.min(tmp,min)
      }
      max = Math.max(max,min)
  }
  return max
};
```