### 解题思路
  const x = [-1, 0, 1, -1, 1,-1, 0, 1]
  const y = [-1, -1, -1, 0, 0, 1, 1, 1]
是当前细胞的八个方向的位置坐标例如(x-1,y-1),(x,y-1)...
当从活细胞变化时，修改成-1，从死细胞变化时，修改成2

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
  let row = board.length
  let col = board[0].length
  const x = [-1, 0, 1, -1, 1,-1, 0, 1]
  const y = [-1, -1, -1, 0, 0, 1, 1, 1]
  for (let i = 0; i < row; i++) {
    for(let j = 0; j < col; j++) {
      let sum = 0
      for(let k = 0; k < 8; k++) {
        let nx = i + x[k]
        let ny = j + y[k]
        if (nx < 0 || ny < 0 || nx > row -1 || ny > col - 1 ) continue
        if(board[nx][ny] === 1 || board[nx][ny] === -1) sum++
      }
      if((sum < 2 || sum > 3) && board[i][j] === 1) {
        board[i][j] = -1
      } else if(sum === 3 && board[i][j] === 0) {
        board[i][j] = 2
      }
      sum = 0
    }
  }
  for (let i = 0; i < row; i++) {
    for(let j = 0; j < col; j++) {
      if(board[i][j] === 2) board[i][j] = 1
      if(board[i][j] === -1) board[i][j] = 0
    }
  }
};

```