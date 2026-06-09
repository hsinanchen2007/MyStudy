## 第一版，三次遍历（不完全暴力解）
> 108ms,37.9M。
1. 对整个9*9宫格遍历三次。依次检查行、列、3\*3宫格
2. 将每行、每列、每个3*3宫格各视为一组数，共有27组数，对每组数使用一个对象来协助检查重复项。
3. 内存中同时最多存在一个有9个键值的对象，空间复杂度比一次遍历低，时间复杂度比完全暴力低
```javascript []
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  for (let i = 0; i < 9; i++) { // 检查行重复项
    let row = {};
    for (let j = 0; j < 9; j++) {
      if (board[i][j] !== '.') {
        if (row[board[i][j]]) return false;
        row[board[i][j]] = 1;
      }
    }
  }
  for (let i = 0; i < 9; i++) { // 检查列重复项
    let col = {};
    for (let j = 0; j < 9; j++) {
      if (board[j][i] !== '.') {
        if (col[board[j][i]]) return false;
        col[board[j][i]] = 1;
      }
    }
  }
  for (let i = 0; i < 9; i += 3) { // 检查3*3宫格重复项
    for (let j = 0; j < 9; j += 3) {
      let miniTable = {};
      for (let m = i; m < i + 3; m++) {
        for (let n = j; n < j + 3; n++) {
          if (board[m][n] !== '.') {
            if (miniTable[board[m][n]]) return false;
            miniTable[board[m][n]] = 1;
          }
        }
      }
    }
  }
  return true;
};
```

## 第二版，一次遍历
> 已经看过题解了，明天（不一定）来写代码

> 112ms,38M。写好了，结果没第一版快？。
```javascript []
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  const rows = [];
  const cols = [{}, {}, {}, {}, {}, {}, {}, {}, {}];
  const tables = [{}, {}, {}, {}, {}, {}, {}, {}, {}];
  for (let i = 0; i < 9; i++) {
    rows[i] = {};
    for (let j = 0; j < 9; j++) {
      if (board[i][j] !== '.') {
        let boxI = ((~~(i / 3)) * 3 + ~~(j / 3));
        if (cols[j][board[i][j]] || rows[i][board[i][j]] || tables[boxI][board[i][j]]) return false;
        cols[j][board[i][j]] = 1;
        rows[i][board[i][j]] = 1;
        tables[boxI][board[i][j]] = 1;
      }
    }
  }
  return true;
};
```