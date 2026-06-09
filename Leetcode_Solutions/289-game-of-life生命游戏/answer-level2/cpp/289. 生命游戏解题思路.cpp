### 解题思路
为了不新增空间，可以将原始数据变成两位2进制数，即 1代表生，0代表死，所以有：
//生到死 10 =》2
//生到生 11 =》3
//死到死 00 =》0
//死到生 01 =》1

然后，也就是最后的数只取二进制数的后面一位数就是结果。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        //生到死 10 =》2
        //生到生 11 =》3
        //死到死 00 =》0
        //死到生 01 =》1

        int h = board.size();
         if(h == 0)
            return;
        int w = board[0].size();
        if(w == 0)
            return;
       
        int sum = 0;
         for(int i = 0;i<h;i++){

            for(int j = 0;j<w;j++){
                 board[i][j] = board[i][j]<<1;
            }
        }

        for(int i = 0;i<h;i++){

            for(int j = 0;j<w;j++){

                sum += lifeOrnot(board,h,w,i-1,j-1);
                sum += lifeOrnot(board,h,w,i-1,j);
                sum += lifeOrnot(board,h,w,i-1,j+1);

                sum += lifeOrnot(board,h,w,i,j+1);
                sum += lifeOrnot(board,h,w,i,j-1);

                sum += lifeOrnot(board,h,w,i+1,j);
                sum += lifeOrnot(board,h,w,i+1,j-1);
                sum += lifeOrnot(board,h,w,i+1,j+1);

                if(sum==3){
                    board[i][j] = board[i][j]+1;
                }
                else if(sum == 2){

                   board[i][j] =  board[i][j]>0?(board[i][j]+1):0;

                }
              
                sum = 0;
            }
        }

         for(int i = 0;i<h;i++){

           for(int j = 0;j<w;j++){

                board[i][j] = board[i][j]&1;
            }
       }

    }

    int lifeOrnot(vector<vector<int>>& board,int h,int w,int x, int y){

        if(x<0||x>=h||y<0||y>=w)
            return 0;

        return (board[x][y]&2)>>1;
    }
};
```