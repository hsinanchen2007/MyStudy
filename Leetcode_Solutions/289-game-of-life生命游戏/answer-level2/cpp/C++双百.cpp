### 解题思路
dfs，把本来是活细胞，结果变成死细胞的标为-1，那么下次遍历的话， -1 也要算成活细胞。
把本来是死细胞，最后变成活细胞的标为2
遍历一遍，最后再遍历一遍 修改值为1 或 0
主要是direction别写错。
### 代码

```cpp
class Solution {
public:
    int direction[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if(row == 0){
            return;
        }
        int col = board[0].size();
        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col; j++){
                int cnt = 0; 
                for(int n = 0; n < 8; n++){
                    int newx = i + direction[n][0];
                    int newy = j + direction[n][1];
                    if(newx < 0 || newx >= row || newy < 0 || newy >= col){
                        continue;
                    }
                    if(board[newx][newy] == 1 || board[newx][newy] == -1){
                        cnt++; 
                    }
                } 
                if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3){
                        board[i][j] = -1;
                    }
                }else{
                    if(cnt == 3){
                        board[i][j] = 2;
                    }
                } 
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == -1){
                    board[i][j] = 0;
                }else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
        return;
    }
 


};
```