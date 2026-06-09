### 解题思路
用DFS解。每次在遍历的时候，先把之前走过的地方临时改下值，递归回来之后再改回来。
BFS无法处理那种折回来之前路径旁边的现象。
### 代码

```cpp
class Solution {
public:
    bool beginExist(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k >= word.size()) {
            return true;
        }
        int m = (int)board.size();
        int n = (int)board[0].size();
        char c = word[k];
        
        if (i + 1 < m && c == board[i+1][j]) {
            char temp = board[i+1][j];
            board[i+1][j] = '.';
            if(beginExist(board, word, i+1, j, k+1)) return true;
            board[i+1][j] = temp;
        }
        
        if (i - 1 >= 0 && c == board[i-1][j]) {
            char temp = board[i-1][j];
            board[i-1][j] = '.';
            if(beginExist(board, word, i-1, j, k+1)) return true;
            board[i-1][j] = temp;
        }
        
        if (j + 1 < n && c == board[i][j+1]) {
            char temp = board[i][j+1];
            board[i][j+1] = '.';
            if(beginExist(board, word, i, j+1, k+1)) return true;
            board[i][j+1] = temp;
        }
        
        if (j - 1 >= 0 && c == board[i][j-1]) {
            char temp = board[i][j-1];
            board[i][j-1] = '.';
            if(beginExist(board, word, i, j-1, k+1)) return true;
            board[i][j-1] = temp;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '.';
                    if (beginExist(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};
```