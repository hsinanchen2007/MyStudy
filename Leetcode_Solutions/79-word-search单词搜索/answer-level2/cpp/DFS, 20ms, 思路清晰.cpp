### 解题思路
用时: 20ms, 96.17%
内存: 10.2MB, 77.95%

DFS搜索十字方向, 走过的地方要留标记, 回溯时利用word清理标记.

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                res = res or dfs(board, word, 0, y, x);
                if (res) return res;
            }
        }
        return res;
    }
    bool dfs(vector<vector<char>>& _board, string& word, int index, int y, int x) {
        if (index == word.size()) return true;
        if (y < 0 or 
            x < 0 or 
            y >= _board.size() or 
            x >= _board[0].size()) return false;
        if (_board[y][x] != word[index]) return false;

        _board[y][x] = '1';

        bool res =  dfs(_board, word, index + 1, y - 1, x) or
                    dfs(_board, word, index + 1, y + 1 ,x) or
                    dfs(_board, word, index + 1, y, x - 1) or
                    dfs(_board, word, index + 1, y, x + 1);
        if (!res) _board[y][x] = word[index];
        return res;
    }
};
```