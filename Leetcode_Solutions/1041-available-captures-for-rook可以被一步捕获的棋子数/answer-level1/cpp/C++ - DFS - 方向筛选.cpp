### 解题思路
DFS方法
加一个flag限制运动方向

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook[2];
        for(int i = 0; i < 8;i++){
            int flag = 0;
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    rook[0] = i;
                    rook[1] = j;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        int ans = move(board, rook[0], rook[1], 0);
        return ans;
    }
    int move(const vector<vector<char>>& board, int i, int j, int flag){
        if(i < 0 || i >= 8 || j < 0 || j >= 8) return 0;
        if(board[i][j] == 'B') return 0;
        if(board[i][j] == 'p') return 1;
        if(flag == 0) return move(board, i - 1, j, 1) + move(board, i + 1, j, 2) + move(board, i, j - 1, 3) + move(board, i, j + 1, 4);
        else if(flag == 1) return move(board, i - 1, j, 1);
        else if(flag == 2) return move(board, i + 1, j, 2);
        else if(flag == 3) return move(board, i , j - 1, 3);
        else return move(board, i, j + 1, 4);
    }
};
```