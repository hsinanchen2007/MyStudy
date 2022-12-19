## 思路
### 代码
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rset(9);
        vector<unordered_set<int>> cset(9);
        vector<unordered_set<int>> bset(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int box = (i / 3) * 3 + j / 3;
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    if (rset[i].count(n) > 0 || cset[j].count(n) > 0 || bset[box].count(n) > 0) {
                        return false;
                    }
                    rset[i].insert(n);
                    cset[j].insert(n);
                    bset[box].insert(n);
                }
            }
        } 
        return true;
    }
};
```
#### 另一种写法
使用vector减少插入set插入时间复杂度。
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rset(9, vector<int>(10));
        vector<vector<int>> cset(9, vector<int>(10));
        vector<vector<int>> bset(9, vector<int>(10));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int box = (i / 3) * 3 + j / 3;
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    if (rset[i][n] != 0 || cset[j][n] != 0 || bset[box][n] != 0) {
                        return false;
                    }
                    rset[i][n] = 1;
                    cset[j][n] = 1;
                    bset[box][n] = 1;
                }
            }
        } 
        return true;
    }
};
```

