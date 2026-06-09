### 解题思路
此处撰写解题思路
1、找到R
2、以R为中心向四个方向走
### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int c, r;
        int res = 0;
        int low, high;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
        }

        low = r;
        high = r;
        while (low >= 0) {
            if (board[low][c] == 'B') {
                break;
            }
            if (board[low][c] == 'p') {
                res++;
                break;
            }
            low--;
        }

        while (high < 8) {
            if (board[high][c] == 'B') {
                break;
            }
            if (board[high][c] == 'p') {
                res++;
                break;
            }
            high++;
        }

        low = c;
        high = c;
        while (low >= 0) {
            if (board[r][low] == 'B') {
                break;
            }
            if (board[r][low] == 'p') {
                res++;
                break;
            }
            low--;
        }

        while (high < 8) {
            if (board[r][high] == 'B') {
                break;
            }
            if (board[r][high] == 'p') {
                res++;
                break;
            }
            high++;
        }
        return res;
    }
};
```