### 解题思路
1. 理解题意后，基本就是一个逻辑翻译的问题；
2. 注意点在于边界条件的小心处理
3. 下面的解法对原矩阵做了一个拷贝，怎么规避？
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        std::vector<std::vector<int>> cp = board;
        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[0].size()); ++j) {
                size_t cnt = getLiveCnt(i, j, cp);
                if (cp[i][j] == 1) {
                    if (cnt < 2u) {
                        board[i][j] = 0;
                    } else if (cnt > 3u) {
                        board[i][j] = 0;
                    }
                } else {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }

private:
    size_t getLiveCnt(const int i, const int j, const std::vector<std::vector<int>>& board) {
        if (board.empty()) {
            return 0;
        }

        size_t cnt = 0;
        for (int m = i-1; m <= i+1; ++m) {
            for (int n = j-1; n <= j+1; ++n) {
                if (m >= 0 && m < static_cast<int>(board.size()) && n >= 0 && n < static_cast<int>(board[0].size())) {
                    if (board[m][n] == 1) {
                        ++cnt;
                    }
                }
            }
        }
        return board[i][j] == 1 ? --cnt : cnt;
    }
};
```