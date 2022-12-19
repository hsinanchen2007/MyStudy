![image.png](https://pic.leetcode-cn.com/1ee99daabab7267a7fbd9b132909e745e0f15751504513ce39a6895bd277f187-image.png)
```
class Solution {
public:
    int r[10][10], c[10][10], x[10][10];
    vector<pair<int, int>> vec;
    int cnt;
    void solveSudoku(vector<vector<char>>& board) {
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(x, 0, sizeof(x));
        cnt = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '0';
                    r[i][t] = 1;
                    c[j][t] = 1;
                    int pos = (i / 3) * 3 + j / 3;
                    x[pos][t] = 1;
                }else {
                    ++cnt;
                    vec.push_back({i, j});
                }
            }
        }
        // cout << "size" << cnt << endl;
        bool flag = false;
        solve(flag, 0, board);
    }

    bool check(int i, int j, int val) {
        int pos = (i / 3) * 3 + j / 3;
        return r[i][val] == 0 && c[j][val] == 0 && x[pos][val] == 0;
    }

    void solve(bool& ok, int now, vector<vector<char>>& board) {
        if (ok) {
            return ;
        }
        // cout << "now = " << now << endl;
        if (now == cnt) {
            ok = true;
            return ;
        }
        for (int i = 1; i <= 9; ++i) {
            int xx = vec[now].first;
            int yy= vec[now].second;
            if (check(xx, yy, i)) {
                r[xx][i] = 1;
                c[yy][i] = 1;
                x[(xx / 3) * 3 + yy / 3][i] = 1;
                board[xx][yy] = i + '0';
                //cout << board[xx][yy]<< endl;
                solve(ok, now + 1, board);
                if (ok) return ;
                board[xx][yy] = '.';
                r[xx][i] = 0;
                c[yy][i] = 0;
                x[(xx / 3) * 3 + yy / 3][i] = 0;
            }
        }
    }
};
```