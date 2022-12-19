### 解题思路
首先，遍历整个棋盘，代码中就是遍历这个二维字符数组，找到车的位置。在我的代码中直接利用循环变量来记录车的位置。当循环到车的位置时，break掉内层循环，同时要break掉外层循环（**如果没有找到车的位置，内层循环总是以8结束，如果内存循环跳出时不是8，说明内层循环被意外终止，也就是找到了车的位置，此时利用这一条件来终止外层循环，就得到了车的位置**）。并且判断棋盘中没有车的情况。

最后，从车的位置一次往他的四个方向来移动，若遇到象，则终止；遇到卒就终止，并将答案加一；直到超出棋盘范围。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_row,rook_col;
        for(rook_row=0;rook_row<8;++rook_row)
        {
            for(rook_col=0;rook_col<8;++rook_col)
            {
                if(board[rook_row][rook_col]=='R') break;
            }
            if(rook_col!=8) break;
        }
        if(rook_row==8&&rook_col==8) return 0;

        int res=0;
        int row=rook_row-1;
        while(row>=0){
            if(board[row][rook_col]=='B') break;
            else if(board[row][rook_col]=='p'){
                res++;
                break;
            }
            row--;
        }

        row=rook_row+1;
        while(row<8){
            if(board[row][rook_col]=='B') break;
            else if(board[row][rook_col]=='p'){
                res++;
                break;
            }
            row++;
        }

        int col=rook_col-1;
        while(col>=0){
            if(board[rook_row][col]=='B') break;
            else if(board[rook_row][col]=='p'){
                res++;
                break;
            }
            col--;
        }

        col=rook_col+1;
        while(col<8){
            if(board[rook_row][col]=='B') break;
            else if(board[rook_row][col]=='p'){
                res++;
                break;
            }
            col++;
        }
        return res;
    }
};
```