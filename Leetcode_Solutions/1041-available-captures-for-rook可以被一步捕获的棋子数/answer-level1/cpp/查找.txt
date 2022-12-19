### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Ri,Rj;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j){
                if(board[i][j] == 'R'){
                    Ri = i;
                    Rj = j;
                }
            }
        int ans = 0;
        for(int i = Ri+1; i < 8; ++i){
            if(board[i][Rj] == 'p'){
                ans++;
                break;
            }
            else if(board[i][Rj] == '.')continue;
            else
                break;
        }
        for(int i = Ri-1;i>=0;--i){
            if(board[i][Rj] == 'p'){
                ans++;
                break;
            }
            else if(board[i][Rj] == '.')continue;
            else
                break; 
        }
        for(int i = Rj+1;i<8;++i){
            if(board[Ri][i] == 'p'){
                ans++;
                break;
            }
            else if(board[Ri][i] == '.')continue;
            else
                break;
        }
        for(int i = Rj-1; i >=0; --i){
            if(board[Ri][i] == 'p'){
                ans++;
                break;
            }
            else if(board[Ri][i] == '.')continue;
            else
                break;
        }
        return ans;
    }
};
```