### 解题思路
思路： 找与车在同行同列上可到达的卒

### 代码

```javascript

var numRookCaptures = function(board) {
  if (!board || board.length === 0) return 0;

  let px;
  let py;
  let count = 0;

  //找到车的位置
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      if (board[i][j] === "R") {
        px = i;
        py = j;
        break;
      }
    }
  }

  //在车所在行，往左找
  for (let k = py - 1; k >= 0; k--) {
    if (board[px][k] === ".") {
      continue;
    }

    if (board[px][k] === "p") {
      count++;
      break;
    }
    break;
  }

  //在车所在行，往右找
  for (let k = py + 1; k <= board[px].length; k++) {
    if (board[px][k] === ".") {
      continue;
    }

    if (board[px][k] === "p") {
      count++;
      break;
    }
    break;
  }

  //在车所在列，往上找
  for (let k = px - 1; k >= 0; k--) {
    if (board[k][py] === ".") {
      continue;
    }
    console.log(board[k][py]);

    if (board[k][py] === "p") {
      count++;
      break;
    }
    break;
  }

  //在车所在行，往下找
  for (let k = px + 1; k < board[px].length; k++) {
    if (board[k][py] === ".") {
      continue;
    }

    if (board[k][py] === "p") {
      count++;
      break;
    }
    break;
  }

  return count;
};


```