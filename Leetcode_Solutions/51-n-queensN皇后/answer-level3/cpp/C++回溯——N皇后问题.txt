![image.png](https://pic.leetcode-cn.com/5c623cd4ab240473ddb2793b91e5a285caac63431cf2271236cde2a23bbd6560-image.png)

### 解题思路
C++回溯，定义三个标记数组分别代表三个限制：若在某一行摆了一个皇后，则皇后位置所在列、45度斜线、135度斜线均不能摆放皇后。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> res;

    void backtrack(int row, int n, vector<string>& nQueens, 
        vector<bool>& colMarked, vector<bool>& diagonals45Marked, vector<bool>& diagonals135Marked) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int diagonals45Idx = row + col;
            int diagonals135Idx = n - 1 - (row - col);
            if (colMarked[col] || diagonals135Marked[diagonals135Idx] || diagonals45Marked[diagonals45Idx]) {
                continue;
            }
            nQueens[row][col] = 'Q';
            colMarked[col] = diagonals135Marked[diagonals135Idx] = diagonals45Marked[diagonals45Idx] = true;
            backtrack(row + 1, n, nQueens, colMarked, diagonals45Marked, diagonals135Marked);
            colMarked[col] = diagonals135Marked[diagonals135Idx] = diagonals45Marked[diagonals45Idx] = false;
            nQueens[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> nQueens(n, string(n, '.'));
        vector<bool> colMarked(n, false);
        vector<bool> diagonals45Marked(2 * n - 1, false);
        vector<bool> diagonals135Marked(2 * n - 1, false);
        backtrack(0, n, nQueens, colMarked, diagonals45Marked, diagonals135Marked);
        return res;
    }
};
```