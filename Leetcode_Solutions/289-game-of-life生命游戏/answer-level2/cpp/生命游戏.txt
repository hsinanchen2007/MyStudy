### 解题思路
照着题目要求无脑遍历就完了。

有个小技巧是把由生变死的细胞的值改为2，由死变生的细胞的值写为-1，
然后在判断周围的活细胞的数量的时候用 >=1

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {0,0,-1,-1,-1,1,1,1};
        int dy[8] = {1,-1,1,-1,0,0,1,-1};
        
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int x=i;
                int y=j;
                int alive=0;
                for(int k = 0;k < 8;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx<0||nx>=m ||ny<0||ny>=n)
                        continue;
                    if(board[nx][ny] >= 1)
                        alive++;
                    
                }
                if(alive<2 && board[x][y]==1)
                    board[x][y]=2;
                if(alive>3 && board[x][y]==1)
                    board[x][y]=2;
                if(alive==3 && board[x][y]==0)
                    board[x][y]=-1;
            }
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == -1)
                    board[i][j] = 1;
                if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};
```