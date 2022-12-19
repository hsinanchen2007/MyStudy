

直接看代码

```cpp
class Solution {

    vector<vector<char>> board;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1 };
public:
    bool exist(vector<vector<char>>& _board, string word) {
        board = _board;
        for (int i = 0; i <  board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (DFS(i,j,0, word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool DFS(int x,int y, int i, string word){
        if ( i == word.size() - 1){
            return board[x][y] == word[i];
        }
        
        if ( board[x][y] == word[i]){
            char cur = board[x][y];
            board[x][y] = '#';
            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if ( nx >= 0 && nx < board.size() &&
                     ny >= 0 && ny < board[x].size()){
                    if ( DFS(nx, ny, i+1, word) ){
                        return true;
                    }        
                }
            }
            board[x][y] = cur;
        }
        return false;
    }
};
```