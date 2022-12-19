

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans=0;
        int st=0,ed=0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    st = i;
                    ed = j;
                    break;
                }
            }
        }
        for(int i=st-1;i>=0;i--){
            if(board[i][ed]=='p'){
                ans++;
                break;
            }
            if(board[i][ed]=='B')
                break;
        }
        for(int i=st+1;i<8;i++){
            if(board[i][ed]=='p'){
                ans++;
                break;
            }
            if(board[i][ed]=='B')
                break;
        }
        for(int i=ed-1;i>=0;i--){
            if(board[st][i]=='p'){
                ans++;
                break;
            }
            if(board[st][i]=='B')
                break;
        }
        for(int i=ed+1;i<8;i++){
            if(board[st][i]=='p'){
                ans++;
                break;
            }
            if(board[st][i]=='B')
                break;
        }
        return ans;
    }
};
```