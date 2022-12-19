### 解题思路
读懂题意，车只能一条路走到黑，最终停止状态有三种情况：1)到达棋盘边缘；2)遇到白色象'B';3)遇到黑色卒'p'。遍历棋盘，遇到白色车时，开始朝四个方向前进，直到坐标抵达边缘或者非空方块停下，然后判断停下的位置board[x][y] == 'p'

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(board[i][j] == 'R'){ //遇到白色车
                    for(int k=0;k<4;k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        while(x>0 && x<7 && y>0 && y<7 && board[x][y]=='.'){
                            x += dx[k];
                            y += dy[k];
                        } //最后一定停在棋盘内，判断该位是否为黑色的卒即可
                        if(board[x][y] == 'p')
                            res++;
                    }
                    return res; //四个方向遍历完毕
                }
        
        return 0;
    }
};
```