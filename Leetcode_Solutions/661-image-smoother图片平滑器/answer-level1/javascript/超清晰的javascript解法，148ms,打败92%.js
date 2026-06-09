### 解题思路
这个没什么技巧，就是遍历。
对于边界判断 用了两个语句
`if (row < 0 || row >= ROW) continue`
` if (col < 0 || col >= COL) continue`
其它都是正常循环的代码
### 代码

```javascript
/**
 * @param {number[][]} M
 * @return {number[][]}
 */
var imageSmoother = function (M) {
  let m = M
  let ROW = m.length
  let COL = m[0].length
  let result = []
  for (let i = 0; i < ROW; i++) {
    result[i] = []
    for (let j = 0; j < COL; j++) {
      let sum = 0, count = 0
      for (let row = i - 1; row <= i + 1; row++) {
        if (row < 0 || row >= ROW) continue
        for (let col = j - 1; col <= j + 1; col++) {
          if (col < 0 || col >= COL) continue
          sum += m[row][col]
          count++
        }
      }
      result[i][j] = Math.floor(sum / count)
    }
  }
  return result
};
```