### 解题思路
首先遍历棋盘找到白色车所在位置；
然后模拟车在四个方向上的行走，遇到空位直接通过，遇到白象停止，遇到黑卒吃掉。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m, n; // 记录车的坐标；
        int dir[2][4] = {{1,0,-1,0},  // x
                         {0,1,0,-1}}; // y
        int ans = 0;
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(board[i][j] == 'R'){
                    m = i;
                    n = j;
                    i = j = 8; // 跳出循环;
                } 
            }
        }
        for(int k = 0; k < 4; ++k){ // 向4个方向进行探索；
            int cur_x = m + dir[0][k];
            int cur_y = n + dir[1][k];
            while(cur_x >= 0 && cur_x < 8 && cur_y >= 0 && cur_y < 8){
                if(board[cur_x][cur_y] != '.'){    // 空位直接通过；
                    if(board[cur_x][cur_y] == 'p') // 吃掉黑卒;
                        ++ans;
                    break;
                }
                cur_x += dir[0][k];
                cur_y += dir[1][k];
            }
        }
        return ans;
    }
};
```