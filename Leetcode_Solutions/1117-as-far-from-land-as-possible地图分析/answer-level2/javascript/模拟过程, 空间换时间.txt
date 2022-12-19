![1162.png](https://pic.leetcode-cn.com/bcf2a5a0167677a10689229d335d2939f111481177b362eb863055a229d70fe8-1162.png)

### 解题思路
1. 筛选出海洋和陆地并记录, 减少后续遍历次数
2. 对于每个海洋, 求其离陆地最近的距离dis
3. 结果为dis中的最大值

### 代码

```javascript
var maxDistance = function(grid) {
  const land = []
  const sea = []
  for (let i = 0; i < grid.length; ++i) {
    for (let j = 0; j < grid[0].length; ++j) {
      if (grid[i][j] === 1) {
        land.push(i)
        land.push(j)
      } else {
        sea.push(i)
        sea.push(j)
      }
    }
  }
  if (land.length === 0 || sea.length === 0) {
    return -1
  } else {
    let res = 0
    for (let i = 0; i < sea.length; i += 2) {
      let minDistance = 10000
      for (let j = 0; j < land.length; j += 2) {
        const distance = Math.abs(sea[i] - land[j]) + Math.abs(sea[i + 1] - land[j + 1])
        minDistance = Math.min(minDistance, distance)
      }
      res = Math.max(res, minDistance)
    }
    return res
  }
};
```