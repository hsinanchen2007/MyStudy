```js
var solveSudoku = function(board) {
  const row = new Array(9).fill(null).map(Object);

  const column = new Array(9).fill(null).map(Object);

  const block = new Array(9).fill(null).map(Object);

  // 初始化约束
  for (let r = 0; r < 9; r++) {
    for (let c = 0; c < 9; c++) {
      const num = board[r][c];

      if (num === ".") continue;

      row[r][num] = true;
      column[c][num] = true;
      block[getBlockIndex(r, c)][num] = true;
    }
  }

  dfs(0, 0);

  function dfs(r, c) {
    // 寻找空位, 无则终点
    while (board[r][c] !== ".") {
      if (++c >= 9) {
        c = 0;
        r++;
      }

      if (r >= 9) return true;
    }

    const blockIndex = getBlockIndex(r, c);

    // 填数
    for (let num = 1; num <= 9; num++) {
      // 约束判断
      if (row[r][num] || column[c][num] || block[blockIndex][num]) continue;

      board[r][c] = String(num);
      row[r][num] = true;
      column[c][num] = true;
      block[blockIndex][num] = true;

      if (dfs(r, c)) return true;

      board[r][c] = ".";
      row[r][num] = false;
      column[c][num] = false;
      block[blockIndex][num] = false;
    }

    return false;
  }

  function getBlockIndex(r, c) {
    return ~~(r / 3) * 3 + ~~(c / 3);
  }
};
```