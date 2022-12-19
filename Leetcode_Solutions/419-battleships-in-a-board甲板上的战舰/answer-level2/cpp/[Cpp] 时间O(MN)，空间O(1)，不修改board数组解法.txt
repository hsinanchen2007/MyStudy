### 解题思路
1. 对于一个战舰当判段到左上角时，res 加1
2. 其余情况如果该位置为X，且该位置上方或者左方有一个X,则表示其不是左上角不进行操作

### 代码

```cpp
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int n = board.size();
        if (n < 1) return res;
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    bool flag = true;
                    if (i - 1 >= 0 && board[i - 1][j] == 'X') flag = false;
                    if (j - 1 >= 0 && board[i][j - 1] == 'X') flag = false;
                    if (flag) res++;
                }
            }
        }

        return res;
    }
};
```