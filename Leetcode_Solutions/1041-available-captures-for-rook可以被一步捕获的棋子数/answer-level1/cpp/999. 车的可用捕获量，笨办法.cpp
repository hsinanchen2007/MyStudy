### 解题思路
找到车再向上下左右找，找到自己的就跳出，找到对方的就记录再跳出

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i,j,R_x=-1,R_y,count=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if (board[i][j]=='R'){
                    R_x=i;
                    R_y=j;
                    break;
                }
            }
            if(R_x>=0) break;
        }
        for(i=R_x-1;i>=0;i--){
            if(board[i][R_y]=='B') break;
            if(board[i][R_y]=='p') {
                //cout<<i<<endl;
                count++;
                break;
            }
        }
        for(i=R_x+1;i<8;i++){
            if(board[i][R_y]=='B') break;
            if(board[i][R_y]=='p'){
                //cout<<i<<endl;
                count++;
                break;
            }
        }
        for(j=R_y-1;j>=0;j--){
            if(board[R_x][j]=='B') break;
            if(board[R_x][j]=='p') {
                //cout<<j<<endl;
                count++;
                break;
            }
        }
        for(j=R_y+1;j<8;j++){
            if(board[R_x][j]=='B') break;
            if(board[R_x][j]=='p') {
                //cout<<j<<endl;
                count++;
                break;
            }
        }
        return count;
    }
};
```