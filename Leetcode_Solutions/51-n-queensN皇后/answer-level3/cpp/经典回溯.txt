### 解题思路

执行用时 :8 ms, 在所有 C++ 提交中击败了88.20% 的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了85.63%的用户

### 代码

```cpp
class Solution {
private:
    vector<vector<string>> res;
    vector<int> pos;
    int L;
public:
    vector<vector<string>> solveNQueens(int n) {
        L = n;
        string row(n, '.');
        vector<string> board(n, row);
        pos.resize(n, -1);
        
        backtrack(0, board);
        
        return res;
    }
    
    void backtrack(int i, vector<string>& board) {
        if(i == L) {
            res.push_back(board);
            return;
        }
        
        for(int j=0; j<L; j++) {
            board[i][j] = 'Q';
            pos[i] = j;
            if(isValid(i, j, board))
                backtrack(i + 1, board);
            board[i][j] = '.';
            pos[i] = -1;
        }
    }
    
    bool isValid(int m, int n, vector<string>& board) {
        for(int i=0; i<m; i++) {
            if(pos[i] == n)           // 同一列
                return false;
            if(abs(i - m) == abs(pos[i] - n))     // 对角线
                return false;
        }
        return true;
    }
};
```