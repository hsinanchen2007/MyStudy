![1.png](https://pic.leetcode-cn.com/b0e1566c5cd9e0fa5ea935fa2d8d909bf28908de81948c73f06cd1704dd85a96-1.png)


### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];

        for (int i = 0; i < 9; ++i) {
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) {
                if(!check(board[i][j], used)) {
                    return false;
                }
            }    // 检查行
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) {
                if (!check(board[j][i], used)) {
                    return false;
                }
            }   // 检查列
        }
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                fill(used, used + 9, false);

                for (int i = r * 3; i < r * 3 + 3; ++i) {
                    for (int j = c * 3; j < c * 3 + 3; ++j) {
                        if (!check(board[i][j], used)) {
                            return false;
                        }
                    }
                } // 3 * 3
            }
        }
        return true;
    }
    bool check(char ch, bool used[9]) {
        if (ch == '.')  return true;
        if (used[ch - '1']) return false;
        return used[ch - '1']  = true;
    }
};
```