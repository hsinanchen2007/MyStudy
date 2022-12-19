### 解题思路
往原数组后push新数组，最后删除原数组本来的子数组

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
  // 方向数组
  const rules = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
    [1,1],
    [1, -1],
    [-1, 1],
    [-1, -1],
  ]
  const len = board.length
  const itemLen = board[0].length
  board.some((item, index) => {
    // 当遍历的次数大于数组原长度的时候停止遍历
    if (index >= len) return true
    // 向原数组push新数组
    board.push([])
    item.forEach((val, i) => {
      // 格子周围存货的细胞数
      let liveCount = 0
      // 遍历方向数组
      rules.some((rule, k) => {
        // x代表子数组的序号， y代表原数组的序号
        let x = i + rule[0], y = index + rule[1]
        // 如果x不小于0并且不大于子数组的长度
        // y不小于0并且不大于数组原长度
        if (x >= 0 && x < itemLen && y >= 0 && y < len) {
          // 如果细胞当前是存活的 liveCount加1
          board[y][x] === 1 ? liveCount += 1 : ''
        }
        if (liveCount > 3) return true
      })
      if (val) {
        if (liveCount >= 2 && liveCount <= 3) {
          board[len + index].push(1)
        } else {
          board[len + index].push(0)
        }
      } else {
        if (liveCount === 3) {
          board[len + index].push(1)
        } else {
          board[len + index].push(0)
        }
      }
    })
  })
  // 删除数组前数组原长度个子数组
  board.splice(0, len)
};
```