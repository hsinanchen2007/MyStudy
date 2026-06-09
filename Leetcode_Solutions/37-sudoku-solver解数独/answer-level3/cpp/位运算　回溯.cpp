### 解题思路
此处撰写解题思路
![2020-04-03 14-04-47 的屏幕截图.png](https://pic.leetcode-cn.com/50b0f3f41ab246535aea2fe3c1f9a55edbb9309e6ebc7bd4807515839662d055-2020-04-03%2014-04-47%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:

    struct Coordinate {
        int x;
        int y;
    };

    int zero = '0';

    bool sudoKubackstrack(vector<vector<char>>& board, deque<Coordinate>& rc,
        vector<int>& row, vector<int>& col, vector<int>& gong) {

        if (rc.empty()) {
            return true;
        }

        auto coord = rc.front();
        
        char c = '1';
        while (c <= zero + 9) {
            int g = (coord.y / 3) * 3 + coord.x / 3;
            int p = c - zero;
            if (((row[coord.x] >> p) & 1) || ((col[coord.y] >> p)  & 1) || ((gong[g] >> p) & 1)) {
                c++;
                continue;
            }

            row[coord.x] ^= (1 << p); col[coord.y] ^= (1 << p); gong[g] ^= (1 << p);
            board[coord.y][coord.x] = c;
            rc.pop_front();
            if (sudoKubackstrack(board, rc, row, col, gong)) return true;
            row[coord.x] ^= (1 << p); col[coord.y] ^= (1 << p); gong[g] ^= (1 << p);
            board[coord.y][coord.x] = '.';
            rc.push_front(coord);
            c++;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        vector<int> row(9, 0);  // 行
        vector<int> col(9, 0);  // 列　
        vector<int> gong(9, 0); // 格
        deque<Coordinate> rc;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int p = board[i][j] - zero;
                    row[j] |= (1 << p);
                    col[i] |= (1 << p);
                    gong[(i / 3) * 3 + j / 3] |= (1 << p);
                } else {
                    rc.push_back({j, i});
                }
            }
        }

        sudoKubackstrack(board, rc, row, col, gong);
    }
};
```