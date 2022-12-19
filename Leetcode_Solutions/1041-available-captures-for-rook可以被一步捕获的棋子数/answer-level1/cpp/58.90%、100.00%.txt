### 解题思路
你有方向数组，我有四个for

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x=0;
        int y=0;
        bool flag=false;
        for(int i=0;i<8;i++){  
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                    flag=true;
                }
            }
            if(flag){
                break;
            }
        }

        int count=0;
        
        for(int i=x,j=y;i<8;i++){
            if(board[i][j]=='B'){
                break;
            }
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int i=x, j=y;i>=0;i--){
            if(board[i][j]=='B'){
                break;
            }
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int j=y, i=x;j>=0;j--){
            if(board[i][j]=='B'){
                break;
            }
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int j=y, i=x;j<8;j++){
            if(board[i][j]=='B'){
                break;
            }
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        return count;

    }
};




/*
[
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".","p",".",".",".","."],
["p","p",".","R",".","p","B","."],
[".",".",".",".",".",".",".","."],
[".",".",".","B",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".",".",".",".",".","."]]

*/
```