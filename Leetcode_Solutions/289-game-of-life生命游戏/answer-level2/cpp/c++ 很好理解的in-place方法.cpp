### 解题思路
in-place算法，分两轮遍历：
1. 第一轮遍历标记
    如果board[i][j]为live且需要修改成dead，那么令board[i][j] = 2;
    如果board[i][j]为dead且需要修改成live, 那么令board[i][j] = -1;

2. 第二轮遍历修改
    将所有的2改成0，所有的-1改成1


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size(), N = board[0].size();
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                int cnt_lives = 0;
                if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] > 0) cnt_lives++;
                if(i-1 >= 0 && board[i-1][j] > 0) cnt_lives++;
                if(i-1 >= 0 && j+1 < N && board[i-1][j+1] > 0) cnt_lives++;
                if(j-1 >= 0 && board[i][j-1] > 0) cnt_lives++;
                if(j+1 < N && board[i][j+1] > 0) cnt_lives++;
                if(i+1 < M && j-1 >= 0 && board[i+1][j-1] > 0) cnt_lives++;
                if(i+1 < M && board[i+1][j] > 0) cnt_lives++;
                if(i+1 < M && j+1 < N && board[i+1][j+1] > 0) cnt_lives++;
                if(board[i][j] > 0){
                    if(cnt_lives < 2 || cnt_lives > 3) board[i][j] = 2;
                }else{
                    if(cnt_lives == 3) board[i][j] = -1;
                }
            }
        }
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
```