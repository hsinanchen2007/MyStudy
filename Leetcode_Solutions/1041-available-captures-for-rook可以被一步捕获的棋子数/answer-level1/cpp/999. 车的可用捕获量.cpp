### 解题思路
1.找到R的位置
2.将R进行上、下、左、右四个方向移动
3.判断break的条件：
    - 遇到B -> break;
    - 超出棋盘界限 -> break;
    - 遇到p -> num++

tips:
    计算机中棋盘坐标原点为左上角，而且得出的横向为y轴，纵向为x轴
### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
    int pos_x = 0;
    int pos_y = 0;
    int mov_x = 0;
    int mov_y = 0;
    int num = 0;//捕获数量
    //定义四个方向的移动
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    //找到 r 的位置
    for(int i = 0; i <8;i++)
    {
        for(int j = 0; j <8; j++ )
        {
            if(board[i][j] == 'R' )
            {
                
            for(int k=0; k<4; k++)
            {
                //初始化车的位置
                mov_x = i;
                mov_y = j;
                while(true)
                {
                    mov_x += dx[k];
                    mov_y += dy[k]; 
                    if(mov_x<0 ||mov_x>7 || mov_y<0 || mov_y>7 ||board[mov_x][mov_y] == 'B')
                    {
                        break;
                    }
                    if(board[mov_x][mov_y] == 'p')
                    {
                        num++;
                        break;
                    }
                }
               
            }
            return num ;
            }

        }

    }
    return 0 ;
    }
};
```