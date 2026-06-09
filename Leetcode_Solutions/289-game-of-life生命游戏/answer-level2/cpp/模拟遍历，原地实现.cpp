### 解题思路
原地解决，利用数值来标识不同的状态，利用表驱动来表示不同的方向和新状态到原始状态的转换。
根据统计数量，按规则转换，
最后，再转换为题目要求的值。

### 代码

```cpp
class Solution {
public:
    int row;
    int col;
    void gameOfLife(vector<vector<int>>& board) {

        row  = board.size();
        if (row == 0) {
            return;
        }
        col  = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
               get_next_state(i, j, board);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] %= 2;
            }
        }        
    }

    bool judge_bound(int x, int y)
    {
        return (x>= 0 && x <row && y >= 0 && y < col);
    }

    void get_next_state(int x, int y, vector<vector<int>>& board)
    {
        // 0  always die
        // 1  always live
        // 2  1->0
        // 3  0->1
        // count 1 & 2 for live number origin, count 0  & 3 for die number origin
        // after process all node, then  vale %= 2
                
        int live_number = 0;
        
        int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1},
                         {-1, 0},            {1, 0},
                         {-1, 1}, {0, 1}, {1, 1}};

        int state[4] = {0, 1, 1, 0};

        for (int d = 0; d < 8; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (judge_bound(nx, ny)) {
                live_number += state[board[nx][ny]];     
            }
        }

        if (live_number < 2 || live_number > 3) {
            board[x][y] =  (board[x][y] == 1) ? 2 : 0;
        }
        if (live_number == 3) {
            board[x][y] = (board[x][y] == 0) ? 3 : 1 ;
        }
    }
};
```