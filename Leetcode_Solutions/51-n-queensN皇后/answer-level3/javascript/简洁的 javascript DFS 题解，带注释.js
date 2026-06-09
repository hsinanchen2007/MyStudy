
简洁的 javascript 题解。

```javascript
var solveNQueens = function(n) {
  let res = []
  dfs(n, [], res)
  return res
}

/**
 * 递归计算 N 皇后的解
 * @param {number} n
 * @param {number[]} tmp 长度为 n 的数组，tmp[i] 代表第 i 行的皇后放置的位置
 * @param {string[]} res
 */
function dfs(n, tmp, res) {
  // 如果 tmp 长度为 n，代表所有皇后放置完毕
  if (tmp.length === n) {
    // 把这种解记录下来
    res.push(
      tmp.map(i => {
        let strArr = Array(n).fill('.')
        strArr.splice(i, 1, 'Q')
        return strArr.join('')
      })
    )
    return
  }
  // 每次有 n 个选择，该次放置在第几列
  for (let j = 0; j < n; j++) {
    // 如果当前列满足条件
    if (isValid(tmp, j)) {
      // 记录当前选择
      tmp.push(j)
      // 继续下一次的递归
      dfs(n, tmp, res)
      // 撤销当前选择
      tmp.pop()
    }
  }
}

function isValid(tmp, j) {
  let i = tmp.length
  for (let x = 0; x < i; x++) {
    let y = tmp[x]
    if (y === j || x - y === i - j || x + y === i + j) {
      return false
    }
  }
  return true
}
```

