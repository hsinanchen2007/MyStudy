### 解题思路
复制一份原始数组，用来记录改变后的细胞状态。模拟过程就行。。
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         
        vector<vector<int> >eboard(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                int count = 0;
                int t = board[i][j];
                int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
                for(int k = 0; k < 8; k++)
                {
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];
                    if(dx >= 0 && dx < board.size() && dy >=0 && dy < board[0].size())
                        if(board[dx][dy] == 1)
                            count++;
                }
                if(count < 2 ||count > 3)
                    t = 0;
                if(count == 3)
                    t = 1;
                eboard[i][j] = t;
            }
        }
       for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = eboard[i][j];
            }
        }
    }
};
```