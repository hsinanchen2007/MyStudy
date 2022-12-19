地图上只有一个车，先找到其位置，之后按照车的位置，按照顺时针的方向遍历当前直线上
可吃掉的卒，可联系之前的一道题寻找地图上存在的岛屿的数量。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int tx=0,ty=0,num=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='R')
                {
                    tx=i;
                    ty=j;
                    break;
                }
            }
        }
        int d_x[4]={1,0,-1,0};
        int d_y[4]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            for(int step=0; ; step++)
            {
                int t_x = tx+step*d_x[i];
                int t_y = ty+step*d_y[i];
                if(t_x<0 || t_x>=8 || t_y<0 || t_y>=8 ||board[t_x][t_y]=='B')
                break;
                if(board[t_x][t_y]=='p')
                {
                    num++;
                    break;
                }
            }
        }
        return num;
    }
};
```