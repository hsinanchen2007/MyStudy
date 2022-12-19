### 解题思路
从当前R位置出发，依次选择四个方向中的一个，直到遇到边界/B点/p点为止

### 代码

```cpp
struct Point {
    int x = 0;
    int y = 0;
};

class Solution {
public:
    Point direction[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // 上/右/下/左
    int numRookCaptures(vector<vector<char>>& board) {
        Point startP;
        bool findStartP = false;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'R') {
                    startP = {i, j};
                    findStartP = true;
                    break;
                }
                if (findStartP) {
                    break;
                }
            }
        }

        int capturesNum = 0;
        for (int i = 0; i < 4; i++) {
            Point p = startP;
            while (isVaild(p.x, p.y, rows, cols) && board[p.x][p.y] != 'B') {
                if (board[p.x][p.y] == 'p') {
                    capturesNum++;
                    break;
                }
                p.x = p.x + direction[i].x;
                p.y = p.y + direction[i].y;
            }
        }

        return capturesNum;
    }

    bool isVaild(int x, int y, int rows, int cols) {
        if (x < 0 || x >= rows) {
            return false;
        }

        if (y < 0 || y >= cols) {
            return false;
        }

        return true;
    }

};
```