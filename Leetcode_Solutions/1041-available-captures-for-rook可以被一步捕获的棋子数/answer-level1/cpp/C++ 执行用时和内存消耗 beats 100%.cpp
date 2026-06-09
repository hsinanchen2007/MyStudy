### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int N = board.size();
        int x = 0, y = 0, mark = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    mark = 1;
                    break;
                }
            }
            if (mark == 1) {
                    break;
            }
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int res = 0;
        for (int i=0; i<4; ++i) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            while(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<N) {
                if (board[tmpx][tmpy] == 'p') {
                    ++res;
                    break;
                }
                if (board[tmpx][tmpy] != '.') {
                    break;
                }
                tmpx += dx[i];
                tmpy += dy[i];
            }
        }
        return res;
    }
};
```