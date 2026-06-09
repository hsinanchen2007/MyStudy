### 解题思路
首先找到R的坐标，然后分别向四个方向查找是否有可达的卒。累加即可。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const int LEN = 8;
        int ans = 0;
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                if (board[i][j] == 'R'){
                    ans += up(board, i, j, LEN);
                    ans += down(board, i, j, LEN);
                    ans += left(board, i, j, LEN);
                    ans += right(board, i, j, LEN);
                    break;
                }
            }
        }

        return ans;

    }

    int  up(vector<vector<char>>& board, int i, int j, int len)
    {
        j--;
        while(j >= 0) {
            if (board[i][j] == 'p') {
                return 1;
            }

            if (board[i][j] == 'B') {
                return 0;
            }
            j--;            
        }

        return 0;
    }


    int  down(vector<vector<char>>& board, int i, int j, int len)
    {
        j++;
        while(j < len) {
            if (board[i][j] == 'p') {
                return 1;
            }

            if (board[i][j] == 'B') {
                return 0;
            }
            j++;            
        }

        return 0;
        
    }


    int  left(vector<vector<char>>& board, int i, int j, int len)
    {
        i--;
        while(i >= 0) {
            if (board[i][j] == 'p') {
                return 1;
            }

            if (board[i][j] == 'B') {
                return 0;
            }
            i--;            
        }

        return 0;
        
    }


    int  right(vector<vector<char>>& board, int i, int j, int len)
    {
        i++;
        while(i < len) {
            if (board[i][j] == 'p') {
                return 1;
            }

            if (board[i][j] == 'B') {
                return 0;
            }
            i++;            
        }

        return 0;
        
    }            
};
```