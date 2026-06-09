### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int x,y;
    void getP(vector<vector<char>> board){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if(board[i][j]=='R'){
                    x = i;
                    y = j;
                    return ;
                }
            }
        }
    }
    int numRookCaptures(vector<vector<char>>& board) {
        getP(board);
        cout<<x<<" "<<y<<endl;
        int sum = 0;
        for(int i = x+1;i<8;i++){
            if(board[i][y]!='.'){
                if(board[i][y]=='p'){
                    sum++;
                }
                break;
            }
        }
        for(int i = x-1;i>=0;i--){
            if(board[i][y]!='.'){
                if(board[i][y]=='p'){
                    sum++;
                }
                break;
            }
        }
        for(int i = y+1;i<8;i++){
            if(board[x][i]!='.'){
                if(board[x][i]=='p'){
                    sum++;
                }
                break;
            }
        }
        for(int i = y-1;i>=0;i--){
            if(board[x][i]!='.'){
                if(board[x][i]=='p'){
                    sum++;
                }
                break;
            }
        }
        return sum;
    }
};
```