
思想方法：
    遍历一次数独，如果不是.就检查行，列，宫。如果有检测失败，直接返回。

```
class Solution {
 public:
  bool check_h(int h, int l, const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      if (l != i && board[h][i] == board[h][l]) {
        return false;
      }
    }
    return true;
  }
  bool check_l(int h, int l, const vector<vector<char>>& board) {
    for (int j = 0; j < 9; j++) {
      if (h != j && board[j][l] == board[h][l]) {
        return false;
      }
    }
    return true;
  }
  bool check_g(int h, int l, const vector<vector<char>>& board) {
    int a = h / 3;
    int b = l / 3;
    for (int i = a * 3; i < a * 3 + 3; i++) {
      for (int j = b * 3; j < b * 3 + 3; j++) {
        if (i != h && j != l && board[i][j] == board[h][l]) {
          return false;
        }
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.')
          if (!check_h(i, j, board) || !check_l(i, j, board) ||
              !check_g(i, j, board)) {
            return false;
          }
      }
    }
    return true;
  }
};
```
