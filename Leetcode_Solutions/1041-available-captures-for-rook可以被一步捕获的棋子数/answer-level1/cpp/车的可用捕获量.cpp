### 解题思路
纯打卡,四个方向扫一遍

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int target_i=0;
        int target_j=0;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='R'){
                    target_i=i;
                    target_j=j;
                    break;
                }
            }
        }
        int result=0;
        for(int j=target_j-1;j>=0;--j){
            if(board[target_i][j]=='p'){
                result+=1;
                break;
            }
            else if(board[target_i][j]=='B'){
                break;
            }
        }
        for(int j=target_j+1;j<board[0].size();++j){
            if(board[target_i][j]=='p'){
                result+=1;
                break;
            }
            else if(board[target_i][j]=='B'){
                break;
            }
        }

        for(int i=target_i-1;i>=0;--i){
            if(board[i][target_j]=='p'){
                result+=1;
                break;
            }
            else if(board[i][target_j]=='B'){
                break;
            }
        }
        for(int i=target_i+1;i<board.size();++i){
            if(board[i][target_j]=='p'){
                result+=1;
                break;
            }
            else if(board[i][target_j]=='B'){
                break;
            }
        }
        
        return result;
    }
};
```