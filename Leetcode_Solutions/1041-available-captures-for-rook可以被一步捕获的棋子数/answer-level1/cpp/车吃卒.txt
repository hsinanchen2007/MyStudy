
### 代码

```cpp
class Solution {
public:

    struct Position{
        int x;
        int y;
        Position(){}
        Position(int x,int y):x(x),y(y){}
    };

    int numRookCaptures(vector<vector<char>>& board) {
        // 先把车找出来
        Position Rpos;
        Position Bpos;
        int row = board.size();
        int col = board[0].size();
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j] == 'R') Rpos = Position(i,j);
            }
        }
        // 从R出发，如果遇到B，这个方向吃不了了，break，如果遇到p，+1，continue
        // 最多也就能吃四个,四个方向分别遍历
        int res = 0;
        for (int i=Rpos.x+1; i<8; i++) {
            int j = Rpos.y;
            if (board[i][j] == 'B') {
                break;
            }
            else if (board[i][j] == 'p') {
                res += 1;
                break;
            }
        }
        for (int i=Rpos.x-1; i>=0; i--) {
            int j = Rpos.y;
            if (board[i][j] == 'B') {
                break;
            }
            else if (board[i][j] == 'p') {
                res += 1;
                break;
            }
        }
        for (int j=Rpos.y+1; j<8; j++) {
            int i = Rpos.x;
            if (board[i][j] == 'B') {
                break;
            }
            else if (board[i][j] == 'p') {
                res += 1;
                break;
            }
        }
        for (int j=Rpos.y-1; j>=0; j--) {
            int i = Rpos.x;
            if (board[i][j] == 'B') {
                break;
            }
            else if (board[i][j] == 'p') {
                res += 1;
                break;
            }
        }
        return res;
    }
};
```