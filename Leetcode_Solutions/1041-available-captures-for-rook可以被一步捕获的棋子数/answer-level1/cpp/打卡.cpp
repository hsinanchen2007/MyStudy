### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
        int res = 0;
        for (int i = 0; i < 8; i ++ ) {
            for (int j = 0; j < 8; j ++ ) {
                if (board[i][j] != 'R') continue;
                int x, y;
                for (int k = 0; k < 4; k ++ ) {
                    x = i + dx[k];
                    y = j + dy[k];
                    while (0 <= x && x< 8 && 0 <= y && y < 8) {
                        if (board[x][y] == 'B') break;
                        if (board[x][y] == 'p') {
                            ++ res;
                            break;
                        }
                        x += dx[k];
                        y += dy[k];
                    }
                }
                return res;
            }
        }
        return res;
    }
};
```