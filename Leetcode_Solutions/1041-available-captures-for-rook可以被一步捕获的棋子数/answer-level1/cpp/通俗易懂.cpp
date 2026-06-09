### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
int x[4] = {0,1,0,-1};//上（0，1）下（0，-1）左（-1，0）右（1，0）四个方向
int y[4] = {1,0,-1,0};
int count = 0;
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'R'){
                    int xn = 0,yn = 0;
                    for(int k=0;k<4;k++){//以R为坐标，分别向四个方向查找
                        xn = x[k] + i;
                        yn = y[k] + j;
                        while(board[xn][yn]=='.'&&xn+x[k]>=0&&xn+x[k]<8&&yn+y[k]>=0&&yn+y[k]<8){//该处是‘.’并且下一个位置没超出棋盘界限的话，就在该方向上继续查找
                            xn+=x[k];
                            yn+=y[k];
                        }
                        if(board[xn][yn] == 'p'){//是目标‘p’的话，就累加，是其他的话就结束循环去另一个方向查找
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
```