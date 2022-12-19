### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rol[] = {0, -1, 0, 1}, col[] = {-1, 0, 1, 0}, total = 0, m, n;
        for(m = 0;m < board.size(); m++){
            for(n = 0; n < board[0].size() && board[m][n] !='R';n++);
            if(n < board[0].size() && board[m][n] =='R')break;
        }
        for(int i = 0; i < 4; i++){
            int dm = m + rol[i], dn = n + col[i];
            while(dm > -1 && dm < board.size() && dn > -1 && dn < board[0].size() && board[dm][dn] != 'B'){
                if(board[dm][dn] == 'p'){
                    total++;
                    break;
                }
                dm += rol[i], dn += col[i];
            }
        }
        return total;
    }
};
```