中心思想就是：边界上的O，肯定是不会被填充为X的，那么跟边界上的O连接的O也不会被填充为X，所以我们只需要把边界上的O以及与边界上的O连接的O先填充成其他字符，最后再遍历整个二维数组，将其中的O填充成X，填充成其他字符的填充回O

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

/*
First, check the four border of the matrix. If there is a element is
'O', alter it and all its nei***or 'O' elements to '1'.

Then ,alter all the 'O' to 'X'

At last,alter all the '1' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X
*/

链接：https://leetcode-cn.com/problems/surrounded-regions/solution/cbeats-9465easy-to-understand-by-zzyuting/


```
class Solution {
public:
    void backTrace(vector<vector<char>>& board, int i, int j)
    {
        if (!(i >= 0 && i < board.size() && j >= 0 && j < board[0].size())) {
            return;
        }

        if (board[i][j] == 'O') {
            board[i][j] = 'Y';
            backTrace(board, i + 1, j);
            backTrace(board, i - 1, j);
            backTrace(board, i, j + 1);
            backTrace(board, i, j - 1);
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int clou = board[0].size();
        int i, j;

        for (i = 0; i < row; i++) {
            backTrace(board, i, 0);
            backTrace(board, i, clou - 1);
        }

        for (j = 0; j < clou; j++) {
            backTrace(board, 0, j);
            backTrace(board, row - 1, j);
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < clou; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};
```
