## 思路
每次可以在四个方向上分别移动一次，先找出'R'位置，然后在四个方向上移动。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int tx, ty, res = 0;
        //1. 找出R位置
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    tx = i;
                    ty = j;
                    break;
                }
            }
        }
        //2. 分别朝四个方向上移动
        for (int i = 0; i < 4; ++i) {
            int step = 0;
            while (step < 8) {
                int x = tx + step * dx[i];
                int y = ty + step * dy[i];
                if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') break;
                if (board[x][y] == 'p') {
                    ++res;
                    break;
                }
                ++step;
            }
        }

        return res;

    }
};
```