### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int row = 0, column = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    row = i;
                    column = j;
                    break;
                }
            }
        }
        int cnt = 0;
        for(int k = 0; k < 4; k++){
            for(int step = 0; ;step++){
                int x = row + dx[k] * step;
                int y = column + dy[k] * step;
                if(x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B')
                    break;
                if(board[x][y] == 'p'){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
```