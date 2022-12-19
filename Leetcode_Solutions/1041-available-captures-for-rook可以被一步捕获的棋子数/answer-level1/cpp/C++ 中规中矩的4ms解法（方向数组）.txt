```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8, x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        int res = 0;
        vector<vector<int>> directs{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
        for (auto d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(board[nx][ny] == '.'){
                    nx += d[0];
                    ny += d[1];
                }
                else{
                    if (board[nx][ny] == 'p')++res;
                    break;
                }
            }
        }
        return res;
    }
};
```