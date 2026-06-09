### 解题思路
设置复合状态来同时表示当前状态和下一状态的

（曾想过要一圈一圈更新，设置辅助数组存储上一圈的状态）

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rlen = board.size();
        if(rlen == 0) return;
        int clen = board[0].size();
        if(rlen == 0) return;
        
        //个位存储当前状态，十位存储周围活细胞数
        for(int i = 0; i < rlen; ++i){
            for(int j = 0; j < clen; ++j){
                for(int x : {-1, 0, 1}){
                    for(int y : {-1, 0, 1}){
                        if(x * y + x + y == 0) continue;
                        if(!isValid(i+x, j+y, rlen, clen)) continue;
                        int temp = board[i + x][j + y];
                        if(temp % 10 == 1){
                            board[i][j] += 10;
                        }
                    }
                }
            }
            
        }

        //更新状态
        for(int i = 0; i < rlen; ++i){
            for(int j = 0; j < clen; ++j){
                switch(board[i][j] / 10){
                    case 2:
                        board[i][j] %= 10;
                        break;
                    case 3:
                        board[i][j] = 1;
                        break;
                    default:
                        board[i][j] = 0;
                        break;
                }
            }
            
        }
    }

    bool isValid(int i, int j, int imax, int jmax)
    {
        if(i > imax - 1) return false;
        if(j > jmax - 1) return false;
        if(i < 0) return false;
        if(j < 0) return false;
        return true;
    }
};
```