
解读题意规则：
 * 如果 ‘1’ 周围< 2个 ‘1’  -> '0'
 * 如果 ‘1’ 周围== [2|3] 个 ‘1’ -> '1'
 * 如果 '1' 周围> 3个 '1' -> '0'
 * 如果 '0' 周围= 3个 ‘1’ -> '1'

思路：
 * 因为细胞只有生(1)死(0)两种状态，所以可以使用二进制位来帮助我们表达更多信息，
 * 即：低位代表当前状态，高位代表下一状态
 * `00` 下一个状态死，当前状态死
 * `01` 下一个状态死，当前状态活  -- 1
 * `10` 下一个状态活，当前状态死  -- 2
 * `11` 下一个状态活，当前状态活  -- 3
 * 取出低位， `board[r][c] & 1`
 * 取出高位， `board[r][c] >> 1`

```javascript
/**
 * 289. Game of Life
 * https://leetcode-cn.com/problems/game-of-life/
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
const gameOfLife = (board) => {
  if (!board.length || !board[0].length) return board
  let rowLength = board.length, colLength = board[0].length
  for (let row = 0; row < rowLength; row++) {
    for (let col = 0; col < colLength; col++) {
      let liveCount = getRoundLiveCount(row, col, board, rowLength, colLength)
      if (board[row][col] === 1) {
        if (liveCount === 2 || liveCount === 3) board[row][col] = 3
      } else if (liveCount === 3) board[row][col] = 2
    }
  }
  for (let row = 0; row < rowLength; row++) {
    for (let col = 0; col < colLength; col++) {
      board[row][col] >>= 1
    }
  }
}

const getRoundLiveCount = (row, col, board, rowLength, colLength, liveCount = 0) => {
  let idx = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [-1, 1], [1, -1], [1, 1]]
  for (let arr of idx) {
    let _row = row + arr[0], _col = col + arr[1]
    if (_row < 0 || _row >= rowLength || _col < 0 || _col >= colLength) continue
    liveCount += (board[_row][_col] & 1)
  }
  return liveCount
}
```