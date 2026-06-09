```
var gameOfLife = function(board) {
  const cloneBoard = board.map(b => b.map(i => i))
  const areas = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
  for (let i = 0; i < cloneBoard.length; i++) {
    for (let j = 0; j < cloneBoard[i].length; j++) {
      let liveCount = 0
      for (let a of areas) {
        if (!cloneBoard[i + a[0]]) continue
        if (cloneBoard[i + a[0]][j + a[1]] === 1) liveCount++
      }
      if (cloneBoard[i][j] === 1 && (liveCount < 2 || liveCount > 3)) {
        board[i][j] = 0
      } else if (liveCount === 3){
        board[i][j] = 1
      }
    }
  }
};
```