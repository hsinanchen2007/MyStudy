### 解题思路
原地修改,不过大家都是0s耗时,做下记录

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        size_t rows = board.size();
        size_t cols = board[0].size();
        for (int x =0 ; x < rows; x++) {
    
            for (int y = 0; y< cols; y++) {
                
                int num = 0;
                
                for (int _x = -1; _x< 2; _x++) {
                    for (int _y = -1; _y< 2; _y++) {
                        int neighborX = x+_x;
                        int neighborY = y+_y;
                        if (neighborY<0 || neighborX<0 || neighborX > rows-1 || neighborY > cols-1)
                            continue;
                        if (neighborY==y && neighborX==x) {
                            continue;
                        }
                        num+=board[neighborX][neighborY]>0?1:0;
                        
                    }
                }
 
                if (board[x][y] && (num<2 || num>3)) {
                    board[x][y]=2;
                }
                else if (num==3 && !board[x][y]) {
                    board[x][y]=-2;
                }
               
            }
        }
        
        for (int x =0 ; x < rows; x++) {
            for (int y = 0; y< cols; y++) {
                if (board[x][y]==-2)
                    board[x][y]=1;
                else if (board[x][y]==2)
                    board[x][y]=0;
            }
        }

    }
};
```