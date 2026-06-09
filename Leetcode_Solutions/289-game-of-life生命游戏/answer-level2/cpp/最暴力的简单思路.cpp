### 解题思路
开辟一个新的二维数组进行判断，但是将判断的结果更改在原来的数组里，这就不会影响原来的数组了~

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    if (board.size()== 0 ||board[0].size() == 0) return;
    vector<vector<int>>board1;
    board1=board;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int M=board1.size();
    int N=board1[0].size();
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {   if(board1[i][j]==0)   //死细胞判断周围是否有满足的条件
            {   int live=0;
                for(int k=0;k<8;k++)
              {
                 int new_x=i+dx[k];
                 int new_y=j+dy[k];
                 if(new_x==-1||new_x==M||new_y==-1||new_y==N)  //判断溢出
                 continue;
                 else
                 {
                   if(board1[new_x][new_y]==0)
                   continue;
                   else
                   live++;
                 }
              }
              if(live==3)    //根据情况修改原数组
             board[i][j]=1;            
            }
            else     //同理判断活细胞周围状况
            {
                int live=0;
                for(int k=0;k<8;k++)
              {
                 int new_x=i+dx[k];
                 int new_y=j+dy[k];
                 if(new_x==-1||new_x==M||new_y==-1||new_y==N)
                 continue;
                 else
                 {
                   if(board1[new_x][new_y]==0)
                   continue;
                   else
                   live++;
                 }
              }
              if(live<2||live>3)
              board[i][j]=0;              
            }
        }
    }
    }
};
```