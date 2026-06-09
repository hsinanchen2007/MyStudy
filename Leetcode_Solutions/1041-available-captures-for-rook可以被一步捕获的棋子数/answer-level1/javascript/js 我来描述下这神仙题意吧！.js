![image.png](https://pic.leetcode-cn.com/2131a128292380f62814be6cb553cd26f7cea38b55ae5913c14cf315b824a084-image.png)

### 描述题意！！！
R：车的起始位置，并且车只能从起始位置向四个方向走
B：路障，遇到就要停车
p：卒子，可以吃，但是这个方向吃了一个卒子也要停，即：每个方向最多吃一个卒子
.：可以继续前进

### 解题思路
```js
  从初始位置向四个方向上去移动，看看能捕获多少个卒
  注意：每个方向吃到一个卒子就不能在这个方向继续吃了
```

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */

var numRookCaptures = function(board) {
  if (board.length === 0 || board[0].length === 0) return 0;
  
  let rowLimit = board.length,
      colLimit = board.length,
      row = null,
      col = null,
      count = 0;
  
  // 找到 R 的位置
  for (let i = 0; i < rowLimit; i++) {
    for (let j = 0; j < colLimit; j++) {
      if (board[i][j] === 'R') {
        row = i;
        col = j;
        break;
      }
    }
    if (row !== null && col !== null) break;
  }
  
  let startRow = row;
  while (startRow >= 0) {
    let c = board[startRow][col];
    if (c === 'B') break;
    if (c === 'p') {
      count++;
      break;
    }
    
    startRow--;
  }
  
  startRow = row;
  while (startRow < rowLimit) {
    let c = board[startRow][col];
    if (c === 'B') break;
    if (c === 'p') {
      count++;
      break;
    }
    
    startRow++;
  }
  
  let startCol = col;
  while (startCol >= 0) {
    let c = board[row][startCol];
    if (c === 'B') break;
    if (c === 'p') {
      count++;
      break;
    }
    
    startCol--;
  }
  
  startCol = col;
  while (startCol < colLimit) {
    let c = board[row][startCol];
    if (c === 'B') break;
    if (c === 'p') {
      count++;
      break;
    }
    
    startCol++;
  }
  
  return count;
};
```