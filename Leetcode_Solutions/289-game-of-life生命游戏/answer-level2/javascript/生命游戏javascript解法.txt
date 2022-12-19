先用一个函数计算位于坐标i, j 位置的细胞其周围的活细胞个数
```javascript
const getAliveCellNum = (board, i, j) => {
    const m = board.length
    const n = board[0].length
    let count = 0
    // 上一行
    if(i > 0) {
      count += board[i-1][j]
      if(j > 0) {
        count += board[i-1][j-1]
      }
      if(j < n-1) {
        count += board[i-1][j+1]
      }
    }
    // 下一行
    if(i < m - 1) {
      count += board[i+1][j]
      if(j > 0) {
        count += board[i+1][j-1]
      }
      if(j < n-1) {
        count += board[i+1][j+1]
      }
    }
    // 左右
    if(j > 0) {
      count += board[i][j-1]
    }
    if(j < n-1) {
      count += board[i][j+1]
    }
    return count
  }
```
循环board数组，根据计算出的活细胞按照题目给出的四条生存定律进行赋值，得到细胞的下一个状态
```javascript
var gameOfLife = function(board) {
  const originBoard = JSON.parse(JSON.stringify(board))
  const m = board.length
  const n = board[0].length

  for(let i = 0;i < m;i++) {
    for(let j= 0;j < n;j++) {
      const num = getAliveCellNum(originBoard, i, j)
      // 先处理死细胞
      if(board[i][j] === 0) {
        if(num === 3) {
          board[i][j] = 1
        }
      } else {  // 处理活细胞
        if(num < 2 || num > 3) {
          board[i][j] = 0
        } 
      }
    }
  }
};
```
