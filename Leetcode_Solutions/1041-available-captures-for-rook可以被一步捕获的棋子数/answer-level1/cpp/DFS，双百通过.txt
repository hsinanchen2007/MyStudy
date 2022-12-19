这道题如果使用DFS的话，可以避免写重复代码，虽然也有点长。。。
不过话说回来，为什么下面的DFS屏蔽掉的那种写法运行速度会比没屏蔽的慢呢？
求大神指导！
```
class Solution {
public:
    int rows = 8, cols = 8;
    int numRookCaptures(vector<vector<char>> &board) {
        vector<pair<int, int>> dir = {{1,  0},
                                      {-1, 0},
                                      {0,  1},
                                      {0,  -1}};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'R') {
                    return DFS(i + dir[0].first, j + dir[0].second, board, dir[0]) + DFS(i + dir[1].first, j + dir[1].second, board, dir[1]) +
                           DFS(i + dir[2].first, j + dir[2].second, board, dir[2]) + DFS(i + dir[3].first, j + dir[3].second, board, dir[3]);
                }
            }
        }
        return 0;
    }
    bool DFS(int row, int col, vector<vector<char>> &board, pair<int, int> dir) {
        if (row < rows && row >= 0 && col < cols && col >= 0 && board[row][col] != 'B') {
            if (board[row][col] == 'p') {
                return true;
            }
            else if (board[row][col] == '.') {
                return DFS(row + dir.first, col + dir.second, board, dir);
            }
            return false;
        }
        else {
            return false;
        }
    }
    <!-- bool DFS(int row, int col, vector<vector<char>> &board, pair<int, int> dir) {
        if (row < rows && row >= 0 && col < cols && col >= 0 && board[row][col] != 'B')
            return board[row][col] == 'p' ? true : DFS(row + dir.first, col + dir.second, board, dir);
        else
            return false;
    } -->
};
```
