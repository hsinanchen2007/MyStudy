## 思路
从第一个节点开始dfs，将已经访问过的位置进行标记，然后递归dfs，接着再进行回溯。
### 代码
```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int depth, int row, int col) {
        int rows = board.size(), cols = board[0].size();
        //越界或值不等
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[depth]) {
            return false;            
        }
        //遍历完字符
        if (depth == word.length()-1) {
            return true;
        }
        char ch = board[row][col];
        board[row][col] = '#'; //设置已经访问
        bool found = dfs(board, word, depth+1, row+1, col) || 
                     dfs(board, word, depth+1, row-1, col) ||
                     dfs(board, word, depth+1, row, col+1) ||
                     dfs(board, word, depth+1, row, col-1);
        board[row][col] = ch;  //回溯
        return found;
    }
};
```
