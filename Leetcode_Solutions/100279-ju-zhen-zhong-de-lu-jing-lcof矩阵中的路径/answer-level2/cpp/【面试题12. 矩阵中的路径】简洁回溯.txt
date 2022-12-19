## 思路
以每个位置开头检查是否存在路径。

### 代码
时间复杂度：O(n * m)
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }                
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int len, string word) {     
        int row = board.size(), col = board[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || word[len] != board[i][j]) return false;      
        if (len == word.size() - 1) return true;
        ++len;
        char ch = board[i][j];
        board[i][j] = '#';
        bool ret = dfs(board, i - 1, j, len, word) ||
                   dfs(board, i + 1, j, len, word) ||
                   dfs(board, i, j - 1, len, word) ||
                   dfs(board, i, j + 1, len, word);        
        board[i][j] = ch; //回溯
        return ret;
    }
};
```

### 另一种写法
使用访问数组表示每个位置是否访问。
时间复杂度：O(n * m)
空间复杂度：O(n * m)
```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();   
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word, visited)) {
                    return true;
                }                
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int len, string word, vector<vector<bool>> &visited) {     
        int row = board.size(), col = board[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || word[len] != board[i][j]) return false;      
        if (len == word.size() - 1) return true;
        ++len;
        visited[i][j] = true;
        bool ret = dfs(board, i - 1, j, len, word, visited) ||
                   dfs(board, i + 1, j, len, word, visited) ||
                   dfs(board, i, j - 1, len, word, visited) ||
                   dfs(board, i, j + 1, len, word, visited);        
        visited[i][j] = false; //回溯
        return ret;
    }
};
```
