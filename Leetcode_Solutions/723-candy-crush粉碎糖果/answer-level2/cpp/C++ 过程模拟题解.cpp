### 代码

```cpp
class Solution {
public:
    const int LINK_COUNT_CUT = 3;
    bool crush(vector<vector<int> >& board, vector<vector<int> >& marks, int R, int C) {
        bool res = false;
        // 遍历行
        for (int i = 0; i < R; ++i) {
            int l = 0;
            for (int j = 0; j < C; ++j) {
                if (board[i][j] != board[i][l]) {
                    if (board[i][l] > 0 && j - l >= LINK_COUNT_CUT) {
                        for (int k = l; k < j; ++k) {
                            marks[i][k] = 1;
                        }
                    }
                    l = j;
                }
            }
            if (board[i][l] > 0 && C - l >= LINK_COUNT_CUT) {
                for (int k = l; k < C; ++k) {
                    marks[i][k] = 1;
                }
            }
        }
        // 遍历列
        for (int j = 0; j < C; ++j) {
            int l = 0;
            for (int i = 0; i < R; ++i) {
                if (board[i][j] != board[l][j]) {
                    if (board[l][j] > 0 && i - l >= LINK_COUNT_CUT) {
                        for (int k = l; k < i; ++k) {
                            marks[k][j] = 1;
                        }
                    }
                    l = i;
                }
            }
            if (board[l][j] != 0 && R - l >= LINK_COUNT_CUT) {
                for (int k = l; k < R; ++k) {
                    marks[k][j] = 1;
                }
            }
        }
        // 更新board，并重置marks
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (marks[i][j] == 1) {
                    board[i][j] = 0;
                    marks[i][j] = 0;
                    res = true;
                }
            }
        }
        return res;
    }
    void refresh(vector<vector<int> >& board, int R, int C) {
        for (int j = 0; j < C; ++j) {
            int i = R - 1;
            for (int k = R - 1; k >= 0; --k) {
                if (board[k][j] > 0) {
                    board[i--][j] = board[k][j];
                }
            }
            while (i >= 0) board[i--][j] = 0;
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        vector<vector<int> > marks(R, vector<int>(C, 0));
        while (crush(board, marks, R, C)) {
            refresh(board, R, C);
        }
        return board;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0f22894e1568e051beba4c6b3131c40bcce70d50cf11afe20fef25816dddee31-image.png)
