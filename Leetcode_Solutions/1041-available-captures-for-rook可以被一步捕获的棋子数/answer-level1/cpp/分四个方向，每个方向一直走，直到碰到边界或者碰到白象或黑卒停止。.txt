### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> moves{{-1,0},{0,1},{1,0},{0,-1}};
        using P = pair<int, int>;
        P p;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    p = P(i, j);
                    break;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<4;i++){
            int x = p.first+moves[i][0];
            int y = p.second+moves[i][1];
            while(x>=0&&x<8&&y>=0&&y<8){
                if(board[x][y]=='p'){
                    ans++;
                    break;
                }else if(board[x][y]=='B'){
                    break;
                }
                x = x+moves[i][0];
                y = y+moves[i][1];
            }
        }
        return ans;
    }
};
```