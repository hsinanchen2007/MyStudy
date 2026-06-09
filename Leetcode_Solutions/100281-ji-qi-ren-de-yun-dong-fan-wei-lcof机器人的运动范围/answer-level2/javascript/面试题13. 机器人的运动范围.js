### 解题思路
此处撰写解题思路
设置一个访问数组记录访问过的路径
顺时针进行搜索
### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
  const visited = []
  for (let i = 0; i < m; i++) {
    visited[i] = []
    for (let j = 0; j < n; j++) {
      visited[i][j] = false
    }
  }

  function _move(row, col) {
    if (row < 0 || row > m - 1 || col < 0 || col > n - 1) return 0

    if (visited[row][col]) return 0

    visited[row][col] = true

    let sum = '' + row + col
    sum = sum.split('').reduce((prev, it) => {
      return prev + +it
    }, 0)

    if (sum <= k) {
      // 顺时针搜索
      const up = _move(row - 1, col)
      const right = _move(row, col + 1)
      const down = _move(row + 1, col)
      const left = _move(row, col - 1)

      return 1 + up + right + down + left
    }

    return 0
  }

  return _move(0, 0)
}
```