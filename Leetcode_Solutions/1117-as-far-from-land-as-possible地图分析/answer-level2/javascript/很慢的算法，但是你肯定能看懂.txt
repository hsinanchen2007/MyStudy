### 解题思路
  1. 找出所有陆地
  2. 计算找出的 海洋和陆地直接的距离，记录每组中的最小值
  3. 从最小值中找最大的距离
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function (grid) {
  let lands = []
  let ocean = []
  let maxMD = -1
  // 找出所有的陆地和海洋
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 1) {
        lands.push([i, j])
      } else {
        ocean.push([i, j])
      }
    }
  }

  for (let [ox, oy] of ocean) {
    //  记录每组最小值
    let _min = Number.MAX_VALUE
    for (let [lx, ly] of lands) {
      let md = Math.abs(ox - lx) + Math.abs(oy - ly)
      if (md < _min) {
        _min = md
      }
    }
    //从最小值中找最大的
    if (_min !== Number.MAX_VALUE && _min>maxMD) {
      maxMD = _min
    }
  }
  return maxMD
};
```
> 这样解题似乎失去了刷题的乐趣🤦‍🤦‍‍🤦‍‍🤦