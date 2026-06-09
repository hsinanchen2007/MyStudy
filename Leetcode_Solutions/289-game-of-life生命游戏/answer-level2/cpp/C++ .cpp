### 解题思路
此处撰写解题思路

主要是给每一个细胞设置一个标志，记录下一时刻应该死亡还是存活。

### 代码

```cpp
class Solution {
    int dir_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dir_y[8] = {1, 1, 1, 0, 0, -1, -1, -1};
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int row = board.size(); //行数
        int col = board[0].size(); //列数
     
        vector<vector<bool>> b(row, vector<bool>(col));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int sum = 0; //统计周围活着的细胞数
                for(int m = 0; m < 8; m++)
                {
                    int new_x = i + dir_x[m];
                    int new_y = j + dir_y[m];
                    if(new_x < 0 || new_y < 0 || new_x > row-1 || new_y > col-1)                                 continue;
                    if(board[new_x][new_y] == 1)
                        sum++;
                }
                if(board[i][j] == 0)
                {
                    if(sum == 3) b[i][j] = true;
                    else b[i][j] = false;
                }
                else if(board[i][j] == 1)
                {
                    if(sum < 2) b[i][j] = false;
                    else if(sum == 2 || sum == 3) b[i][j] = true;
                    else if(sum > 3) b[i][j] = false;
                }
            }
        }
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(b[i][j] == true)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};

```