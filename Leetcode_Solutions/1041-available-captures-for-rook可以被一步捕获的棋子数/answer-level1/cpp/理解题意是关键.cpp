### 解题思路
此处撰写解题思路
1、读懂题目的意思，一次操作指的是上下左右四个方向都可以移动
2、按四个方向扫描，注意及时break

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // 先找到 che 的位置 
        int startX = 0;
        int startY = 0;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    startX = i;
                    startY = j;
                    break;
                }
            }
        }

        int cnt = 0;
        // 向右走 
        for (int j = startY; j < 8; j++) {
            if (j + 1 < 8) {
                if (board[startX][j + 1] == 'p') {
                    cnt++;
                    break;
                }
                if (board[startX][j + 1] == 'B') {
                    break;
                }
            }
        }

        // 向左走
        for (int j = startY; j >= 0; j--) {
            if (j - 1 >= 0) {
                if (board[startX][j - 1] == 'p') {
                    cnt++;
                    break;
                }
                if (board[startX][j - 1] == 'B') {
                    break;
                }
            }
        }

        // 向上走
        for (int i = startX; i >= 0; i--) {
            if (i - 1 >= 0) {
                if (board[i - 1][startY] == 'p') {
                    cnt++;
                    break;
                }
                if (board[i - 1][startY] == 'B') {
                    break;
                }
            }
        }

        // 向下走
        for (int i = startX; i < 8; i++) {
            if (i + 1 < 8) {
                if (board[i + 1][startY] == 'p') {
                    cnt++;
                    break;
                }
                if (board[i + 1][startY] == 'B') {
                    break;
                }
            }
        }

        return cnt;
    }
};
```