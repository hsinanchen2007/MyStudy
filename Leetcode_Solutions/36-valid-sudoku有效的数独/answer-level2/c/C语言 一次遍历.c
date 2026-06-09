使用三个数组分别保存 行，列，九宫格 中出现的数字，一次遍历再次出现返回 false；
一次遍历主要问题在：如何同时检索九宫格；
```
for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
        r = 3 * (i / 3) + j / 3; //行
        c = (i % 3) * 3 + j % 3; //列
    }
}
<!-- 每行为一次遍历，刚好是一个九宫格 -->
(0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2) 
(0,3) (0,4) (0,5) (1,3) (1,4) (1,5) (2,3) (2,4) (2,5) 
(0,6) (0,7) (0,8) (1,6) (1,7) (1,8) (2,6) (2,7) (2,8) 
(3,0) (3,1) (3,2) (4,0) (4,1) (4,2) (5,0) (5,1) (5,2) 
(3,3) (3,4) (3,5) (4,3) (4,4) (4,5) (5,3) (5,4) (5,5) 
(3,6) (3,7) (3,8) (4,6) (4,7) (4,8) (5,6) (5,7) (5,8) 
(6,0) (6,1) (6,2) (7,0) (7,1) (7,2) (8,0) (8,1) (8,2) 
(6,3) (6,4) (6,5) (7,3) (7,4) (7,5) (8,3) (8,4) (8,5) 
(6,6) (6,7) (6,8) (7,6) (7,7) (7,8) (8,6) (8,7) (8,8) 
```
代码如下：
```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  int i, j, r, c, row[9], col[9], martix[9];
  for (i = 0; i < boardSize; i++) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(martix, 0, sizeof(martix));
    for (j = 0; j < boardColSize[i]; j++) {
      // 行
      if (board[i][j] != '.') {
        if (row[board[i][j] - '1'] == 1) return false;
        row[board[i][j] - '1']++;
      }
      // 列
      if (board[j][i] != '.') {
        if (col[board[j][i] - '1'] == 1) return false;
        col[board[j][i] - '1']++;
      }
      // 九宫格
      r = 3 * (i / 3) + j / 3;
      c = (i % 3) * 3 + j % 3;
      if (board[r][c] != '.') {
        if (martix[board[r][c] - '1'] == 1) return false;
        martix[board[r][c] - '1']++;
      }
    }
  }
  return true;
}
```