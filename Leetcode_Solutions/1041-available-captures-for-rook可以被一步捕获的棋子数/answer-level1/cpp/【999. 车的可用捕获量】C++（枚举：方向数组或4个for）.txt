### 解题思路
枚举四个方向：四个for或者方向数组；
![image.png](https://pic.leetcode-cn.com/a27400c30a2cd7e70ecb8cd14615b48baa10a404049f6cdbf3999fa281af5153-image.png)
**一点优化**：找R的同时统计p的总数，之后遍历的时候一旦res等于总数直接返回。
### 代码

```cpp []
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int total_p = 0;
        int res = 0;
        int R_row = 9, R_col = 9;
        for(int i =0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(board[i][j]=='p')
                    total_p++;
                if(board[i][j]=='R')
                    R_row = i, R_col = j;
            }
        }
        // 枚举四个方向
        int cur_row, cur_col;
        cur_col = R_col;
        cur_row = R_row;
        while(cur_row--){
            cout<<board[cur_row][cur_col]<<endl;
            if(board[cur_row][cur_col]=='.')
                continue;
            else if(board[cur_row][cur_col]=='p'){
                res++;
                if(res==total_p)
                    return res;
                else
                    break;
            }
            else
                break;
        }
        cur_row = R_row;
        while(++cur_row<8){
            if(board[cur_row][cur_col]=='.')
                continue;
            else if(board[cur_row][cur_col]=='p'){
                res++;
                if(res==total_p)
                    return res;
                else
                    break;
            }
            else
                break;
        }
        cur_row = R_row;
        cur_col = R_col;
        while(cur_col--){
            if(board[cur_row][cur_col]=='.')
                continue;
            else if(board[cur_row][cur_col]=='p'){
                res++;
                if(res==total_p)
                    return res;
                else
                    break;
            }
            else
                break;
        }
        cur_col = R_col;
        while(++cur_col<8){
            if(board[cur_row][cur_col]=='.')
                continue;
            else if(board[cur_row][cur_col]=='p'){
                res++;
                if(res==total_p)
                    return res;
                else
                    break;
            }
            else
                break;
        }
        return res;
    }
};
```
```cpp []
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int total_p = 0;
        int res = 0;
        int R_row = 9, R_col = 9;
        for(int i =0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(board[i][j]=='p')
                    total_p++;
                if(board[i][j]=='R')
                    R_row = i, R_col = j;
            }
        }
        // 方向数组
        int cur_row, cur_col;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
            for (int step = 0;; ++step) {
                int cur_row = R_row + step * dx[i];
                int cur_col = R_col + step * dy[i];
                if (cur_row < 0 || cur_row >= 8 || cur_col < 0 || cur_col >= 8 || board[cur_row][cur_col] == 'B') 
                    break;
                if (board[cur_row][cur_col] == 'p') {
                    res++;
                    if(res==total_p)
                        return res;
                    break;
                }
            }
        }

        return res;
    }
};
```
