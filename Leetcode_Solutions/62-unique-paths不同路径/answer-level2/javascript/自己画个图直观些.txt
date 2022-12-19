
![IMG_0499.jpg](https://pic.leetcode-cn.com/aaa94d31c8d9b65decd41863fc2a708b5b5cacd7e5f26afb20cbf7bf4af06b86-IMG_0499.jpg)






```javascript []
var uniquePaths = function(m, n) {
  if (m === 1 && n === 1) return 1
  let list = Array.from({ length: n }, _ => Array.from({ length: m }, _ => 0))
  for (let i = 1; i < m; i++) {
    list[0][i] = 1
  }
  for (let i = 1; i < n; i++) {
    list[i][0] = 1
  }
  for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
      list[i][j] = list[i][j - 1] + list[i - 1][j]
    }
  }
  return list[n - 1][m - 1]
}
```
