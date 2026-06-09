### 解题思路
数独模板，与N皇后问题类似
### 代码

```cpp
class Solution {
public:
    bool row[9][9] = {0}, col[9][9] = {0},cell[3][3][9] = {0};

    void solveSudoku(vector<vector<char>>& board) {
        for(int i  = 0; i<9; i++)
            for(int j = 0; j < 9; j++)
            {
                char c =board[i][j];
                if(c != '.')
                {
                    int t =  c - '1';
                    row[i][t] = col[j][t] = cell[i/3][j/3][t] = true;
                }
            }
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>&board, int x ,int y)
    {
        //出界去下一行
        if(y == 9)x++ , y= 0;
        if(x == 9)return true;
        if(board[x][y] != '.')return dfs(board,x ,y + 1);
        for(int i= 0 ; i < 9; i++){
            if(!row[x][i] && !col[y][i]&& !cell[x/3][y/3][i])
            {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
                if(dfs(board,x,y+1))return true;
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
                board[x][y] ='.';
            }
        } 

        return false;
    }
};
```