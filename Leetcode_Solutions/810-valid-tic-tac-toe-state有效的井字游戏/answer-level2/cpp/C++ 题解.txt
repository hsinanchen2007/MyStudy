```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        const int K = 3;
        int rows[K][2] = {0};
        int cols[K][2] = {0};
        int diag1[2] = {0};
        int diag2[2] = {0};
        int nx = 0;
        int no = 0;
        int winx = 0;
        int wino = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                if (board[i][j] != ' ') {
                    int ind = board[i][j] == 'X' ? 0 : 1;
                    nx += ind == 0;
                    no += ind == 1;
                    int& w = ind == 0 ? winx : wino;
                    if (++rows[i][ind] == K) ++w;
                    if (++cols[j][ind] == K) ++w;
                    if (i + j == K - 1 && ++diag2[ind] == K) ++w;
                    if (i == j && ++diag1[ind] == K) ++w;
                    if (winx > 0 && wino > 0) return false;
                }
            }
        }
        if (winx) return nx - no == 1;
        if (wino) return nx == no;
        return nx - no == 1 || nx - no == 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8f0630773d6c8c75bd09b42013fc6316fc88a9b9e37e0079cac1cef72048a2d4-image.png)
