### 解题思路
感谢[花花酱](https://www.youtube.com/watch?v=Xa-yETqFNEQ&list=PLLuMmzMTgVK423Mj1n_OaOAZZ6k5fNxyN&index=42)的讲解
我今天一定要把回溯系列搞明白了！


### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        column = vector<int>(n,0); //每列状态
        diag_a = vector<int>(2*n-1, 0);//主对角线状态
        diag_b = vector<int>(2*n-1, 0);//副对角线状态
        vector<string> board(n,string(n,'.')); //棋盘
        //从第一行开始放
        backtrack(board, n, 0);
        return ans;
    }
    void backtrack(vector<string>& board, int n, int row) {
        //如果行数超出了棋盘，说明已经找到了一种布局
        if (n == row) {
            ans.push_back(board);
            return ;
        }
        //对于一行的每一列：
        for (int i = 0; i < n; ++i) {
            //做选择,这里不止在棋盘上放上皇后，并且把相应的列和正反对角线设置一个状态，达到剪枝的目的
            //这里很关键，如果当前格子所在的列，或者主对角线，或者副对角线不能放，那么就跳过当前格子！
            if (column[i] || diag_a[row-i+n-1] || diag_b[row+i])   continue;
            //board[row][i] = 'Q';
            updateBoard(board, n, row, i, true);
            //下一行
            backtrack(board, n, row + 1);
            //撤销选择
            updateBoard(board, n, row, i, false);
        }

    }
private:
    vector<vector<string>> ans;
    //下面分别是每一列、主对角线、副对角线
    vector<int> column;
    vector<int> diag_a;
    vector<int> diag_b;
    //这里的put_flag代表放置了皇后，被标记的地方不能再放
    void updateBoard(vector<string>& board, int n, int row, int x, bool put_flag) {
        column[x] = put_flag;
        diag_a[row-x+n-1] = put_flag;
        diag_b[row+x] = put_flag;
        //如果传入的状态是true，放入Q，否则放入.
        board[row][x] = put_flag ? 'Q' : '.';

    }
};
```