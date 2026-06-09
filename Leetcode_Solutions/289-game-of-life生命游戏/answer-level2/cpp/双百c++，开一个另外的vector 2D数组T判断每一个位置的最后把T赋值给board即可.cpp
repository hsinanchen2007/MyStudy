### 解题思路
开一个另外的vector 2D数组T判断每一个位置的最后把T赋值给board即可

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> >T(board.size(),vector<int>(board[0].size()));
        int row = board.size(), col = board[0].size();
        int c = 0;//记录每个
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                c=0;
                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (board[i - 1][j - 1] == 1) c++;
                }
                if (i - 1 >= 0) {
                    if (board[i - 1][j] == 1) c++;
                }
                if (i - 1 >= 0 && j + 1 < col) {
                    if (board[i - 1][j + 1] == 1) c++;
                }

                if ( j - 1 >= 0) {
                    if (board[i][j - 1] == 1) c++;
                }
                if (j + 1 <col) {
                    if (board[i][j + 1] == 1) c++;
                }

                if (i + 1 <row && j - 1 >= 0) {
                    if (board[i + 1][j - 1] == 1) c++;
                }
                if (i + 1 <row) {
                    if (board[i + 1][j] == 1) c++;
                }
                if (i + 1 <row && j + 1 < col) {
                    if (board[i + 1][j + 1] == 1) c++;
                }
                if (board[i][j] == 1 && (c == 2 || c == 3)) T[i][j] = 1;
                else if (board[i][j] == 0 && c == 3) T[i][j] = 1;
                else T[i][j] = 0;
            }
        }
        for (int i = 0; i < row; i++) {
            board[i]=T[i];
        }
    }
};
```