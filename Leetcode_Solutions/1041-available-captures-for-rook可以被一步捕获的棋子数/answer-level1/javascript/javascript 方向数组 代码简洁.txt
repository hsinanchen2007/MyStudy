此题就是考察大家的编程基本功的，根据题意，以 R 为起点进行四连通遍历检索，注意这里使用了 dx, dy 来限制每次只能向单一方向递进

```javascript
/**
 * 999. Available Captures for Rook
 * https://leetcode-cn.com/problems/available-captures-for-rook/
 * @param {character[][]} board
 * @return {number}
 */
const numRookCaptures = (board) => {
  let count = 0, dxy = [[-1, 0], [1, 0], [0, -1], [0, 1]]
  const dfs = (i, j, dx, dy) => {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return 
    if (board[i][j] === 'B') return
    if (board[i][j] === 'p') { ++count; return }
    dfs(i + dx, j + dy, dx, dy)
  }

  for (let i = 0; i < 8; ++i) {
    for (let j = 0; j < 8; ++j) {
      if(board[i][j] != 'R') continue
      for (let arr of dxy) {
        dfs(i + arr[0], j + arr[1], arr[0], arr[1])
      }
    }
  }

  return count
}
```