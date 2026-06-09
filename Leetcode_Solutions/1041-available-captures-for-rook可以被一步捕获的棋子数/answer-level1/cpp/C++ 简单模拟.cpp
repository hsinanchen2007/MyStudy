### 解题思路
题意是：从车的当前位置分别从四个方向向前试探，如果有一个方向的路上遇到白象，这条路就结束了（但往其他方向走的并不影响）；如果有一个方向遇到黑卒，就吃掉，并且不再向前进，这条路也结束了。
也就是说，答案最多是4.

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int direction[][4]={
            0,1,
            0,-1,
            1,0,
            -1,0
        };
        int x=0,y=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                } 
            }
        }
        int cnt=0;
        for(int k=0;k<4;k++){
            for(int step=0;;++step){//每次往前走一步
                int tx=x+step*direction[0][k];
                int ty=y+step*direction[1][k];
                if(tx<0||tx>=8||ty<0||ty>=8||board[tx][ty]=='B')
                    break;//换另一个方向继续试
                if(board[tx][ty]=='p')
                {
                    cnt++;
                    break;
                }
                
            }
        }
        return cnt;
    }
};
```