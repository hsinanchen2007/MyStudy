既然0表示死亡，1表示活着。那么我们可以用-1表示下一个状态是从活着变成死亡，-2表示死亡变成活着。

```
/****
 * 0: 死亡
 * 1: 活着
 * -1: 活着-->死亡
 * -2: 死亡-->活着
 * ******/
class Solution {
 public:
  int move[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  //计算周围活细胞的数目
  int count_alive(vector<vector<int>>& board, int x, int y, int m, int n) {
    int rslt = 0;
    for (int i = 0; i < 8; i++) {
      int cx = x + move[i][0];
      int cy = y + move[i][1];
      if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
      if (board[cy][cx] == 1 || board[cy][cx] == -1) rslt++;
    }
    return rslt;
  }

  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++) {
        int alive_cell_cnt = count_alive(board, x, y, m, n);
        if (board[y][x] == 1) {  // alive
          if (alive_cell_cnt < 2 || alive_cell_cnt > 3)
            board[y][x] = -1;  // biss
        } else {
          if (alive_cell_cnt == 3)  // 给你套个复活甲
            board[y][x] = -2;
        }
      }

    // Update
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++) {
        if (board[y][x] == -1)
          board[y][x] = 0;
        else if (board[y][x] == -2)
          board[y][x] = 1;
      }

  }
};
```
