### 解题思路
遍历整个矩阵
1）找到R；
2）遍历四个方向；

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'R'){
                    int x = i-1;
                    int y = j;
                    while(x >= 0 && board[x][y] == '.'){
                        x--;
                    }
                    if(x >= 0 && board[x][y] == 'p'){
                        res++;
                    }
                    x = i + 1;
                    while(x < m && board[x][y] == '.'){
                        x++;
                    }
                    if(x < m && board[x][y] == 'p'){
                        res++;
                    }

                    x = i;
                    y = j - 1;

                    while(y >= 0 && board[x][y] == '.'){
                        y--;
                    }
                    if(y >= 0 && board[x][y] == 'p'){
                        res++;
                    }

                    y = j + 1;
                    while(y < n && board[x][y] == '.'){
                        y++;
                    }
                    if(y < n && board[x][y] == 'p'){
                        res++;
                    }
                    return res;
                }
            }
        }
        return 0;
    }
};
```