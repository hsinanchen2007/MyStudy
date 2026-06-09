### 解题思路
live -> dead : 1 -> -1
dead -> live : 0 -> 2 

### 代码

```cpp
class Solution {
public:
    vector<int> dx = {-1, 0 ,1};
    vector<int> dy = {-1, 0 ,1};
    void gameOfLife(vector<vector<int>>& board) {
        size_t m = board.size();
        size_t n = board[0].size();
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                int curCount = 0;
                bool flag = false;
                for (int dxx : dx) {
                    for (int dyy : dy) {
                        if (dxx == 0 && dyy == 0) {
                            continue;
                        }
                        int nextx = i + dxx;
                        int nexty = j + dyy;
                        if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && (board[nextx][nexty] == 1 || board[nextx][nexty] == -1)) {
                            curCount++;
                        }
                    }
                }
                if (board[i][j] == 1 || board[i][j] == -1) {
                    // live
                    if (curCount < 2 || curCount > 3) {
                        board[i][j] = -1;
                    }
                } else if (curCount == 3) {
                    // dead
                    board[i][j] = 2;
                }                
            }
        }
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (board[i][j] < 0) {
                    board[i][j] = 0;
                } else if (board[i][j] > 1) {
                    board[i][j] = 1;
                } 

            }
        }
    }
};

```