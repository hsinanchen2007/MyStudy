1. 因为只有两种状态，活或者死，因此可以设活为正，死为负
2. 如果周围都是死细胞，活着置为9，死置为-9
3. 遍历数组，活着是正，死是负，统计周围所有正数。
4. 再次遍历数组，按照规则一一修改。
 ```
class Solution {
public:
    int rows;
    int cols;

    void checkUp(int row, int col, vector<vector<int>>& board) {
        int count = 0;
        int flag = 1;   //死活记位
        if (board[row][col] < 1) flag = -1;
        //左上
        if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] > 0)count++;
        //上中
        if (row - 1 >= 0 && board[row - 1][col] > 0)count++;
        //右上
        if (row - 1 >= 0 && col + 1 <= cols && board[row - 1][col + 1] > 0)count++;
        //左
        if (col - 1 >= 0 && board[row][col - 1] > 0)count++;
        //右
        if (col + 1 <= cols && board[row][col + 1] > 0)count++;
        //左下
        if (row + 1 <= rows && col - 1 >= 0 && board[row + 1][col - 1] > 0)count++;
        //中下
        if (row + 1 <= rows && board[row + 1][col] > 0)count++;
        //右下
        if (row + 1 <= rows && col + 1 <= cols && board[row + 1][col + 1] > 0)count++;
        count = flag * count;
        //周围都是死细胞的情况
        if (count == 0 && board[row][col] == 1) count = 9;
        if (count == 0 && board[row][col] == 0) count = -9;
        board[row][col] = count;
    }

    void renew(int row, int col, vector<vector<int>>& board) {
        bool alive; //死活标记
        if (board[row][col] < 0) alive = false;
        if (board[row][col] > 0) alive = true;
        int count = abs(board[row][col]);
        if (count < 2 && alive) board[row][col] = 0;
        else if ((count == 2 || count == 3) && alive) board[row][col] = 1;
        else if (count > 3 && alive) board[row][col] = 0;
        else if (count ==3 && !alive) board[row][col] = 1;
        else board[row][col] = 0;
    }

    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size() - 1;
        cols = board[0].size() - 1;

        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j <= cols; j++) {
                checkUp(i, j, board);
            }
        }

        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j <= cols; j++) {
                renew(i, j, board);
            }
        }
    }
};
```
