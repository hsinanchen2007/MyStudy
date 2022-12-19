### 解题思路
暴力法：分4个方向寻找
### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int R_r = -1;
        int R_c = -1;

        if (board.size() == 0) {
            return 0;
        }

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == 'R') {
                    R_r = r;
                    R_c = c;
                }
            }
        }

        //cout << "Rc" << R_r << "," << R_c << endl;

        if (R_r == -1 && R_c == -1) {
            return 0;
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int sum = 0;

        for (int k = 0; k < 4; ++k) {
            int tmpr = R_r;
            int tmpc = R_c;

            for (int i = 0; i < 8; ++i) {
                tmpr += dr[k];
                tmpc += dc[k];

                if (tmpr < 0 || tmpr >= board.size() ||
                    tmpc < 0 || tmpc >= board[0].size()) {
                        break;
                }

                if (board[tmpr][tmpc] == 'p') {
                    //cout << tmpr << ", " << tmpc << endl;
                    ++sum;
                    break;
                } else if (board[tmpr][tmpc] == 'B') {
                    break;
                }
            }
        }

        return sum;
    }
};
```