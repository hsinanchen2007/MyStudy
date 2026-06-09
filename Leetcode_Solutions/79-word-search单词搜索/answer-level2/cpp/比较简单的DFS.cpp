```C++ []
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int x,
             vector<vector<int>>& visited){
        if( i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            x >= word.size() || board[i][j] != word[x] || visited[i][j])
            return 0;
        else if(x == word.size() - 1 && board[i][j] == word[x])
            return 1;
        else{
            visited[i][j] = 1;
            bool m1 = dfs(board, i - 1, j, word, x + 1, visited);
            if(m1) return 1;
            bool m2 = dfs(board, i + 1, j, word, x + 1, visited);
            if(m2) return 1;
            bool m3 = dfs(board, i, j - 1, word, x + 1, visited);
            if(m3) return 1;
            bool m4 = dfs(board, i, j + 1, word, x + 1, visited);
            if(m4) return 1;
            visited[i][j] = 0;
            return 0;  
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0, visited)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

```
因为开始未必在（0， 0）的位置，因此需要遍历所有的节点找起点。