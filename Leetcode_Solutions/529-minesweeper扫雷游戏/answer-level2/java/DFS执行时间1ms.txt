### 解题思路
主要分为几个步骤吧，首先是判断这个位置是不是雷，是雷直接更改为x然后退出
如果不是雷，那么是不是B（空白），是的话直接退出
如果都不是那么就只能是点到了E，那么就进行大面积更改

更改的原则是这样的，如果碰到8个方向均没有雷的，就直接改为B，并且再递归，也就是查看相邻的位置（这个地方我刚开始写错了还是看了题解的第一个大佬说的“是按照四面八方走的不是上下左右再改过来的”）
如果8个方向存在雷，就返回雷的个数，并且！不再向四面八方递增！
写法如果优化的话应该就是在最后的确定四面八方是否存在雷的地方进行优化了！

![截屏2020-03-04下午5.18.55.png](https://pic.leetcode-cn.com/0c3d7a276d60afdef66ecdd49cc48d9e7bcb3a7d6104b9f2159e6a4d1a2ef35a-%E6%88%AA%E5%B1%8F2020-03-04%E4%B8%8B%E5%8D%885.18.55.png)


### 代码

```java
class Solution {
    char[][] b;

    public char[][] updateBoard(char[][] board, int[] click) {
        if (board.length == 0 || board[0].length == 0)
            return board;
        int rows = board.length, cols = board[0].length;
        if (click[0] < 0 || click[0] >= rows || click[1] < 0 || click[1] >= cols) {
            return board;
        }
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]] == 'B')
            return board;
        b = board;
        changeboard(click[0], click[1], rows, cols);
        return b;
    }

    public void changeboard(int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;
        if (b[i][j] == 'E') {
            if (getcount(i, j, rows, cols) == 0) {
                b[i][j] = 'B';
                changeboard(i - 1, j, rows, cols);
                changeboard(i + 1, j, rows, cols);
                changeboard(i, j - 1, rows, cols);
                changeboard(i, j + 1, rows, cols);
                changeboard(i-1,j-1,rows,cols);
                changeboard(i-1,j+1,rows,cols);
                changeboard(i+1,j-1,rows,cols);
                changeboard(i+1,j+1,rows,cols);
            } else {
                b[i][j] = (char) (getcount(i, j, rows, cols) + '0');
                return;
            }
        } else
            return;
    }

    public int getcount(int i, int j, int rows, int cols) {
        int res = 0;
        if (i - 1 >= 0) {
            if (j - 1 >= 0 && b[i - 1][j - 1] == 'M')
                res++;
            if (b[i - 1][j] == 'M')
                res++;
            if (j + 1 < cols && b[i - 1][j + 1] == 'M')
                res++;
        }
        if (i + 1 < rows) {
            if (j - 1 >= 0 && b[i + 1][j - 1] == 'M')
                res++;
            if (b[i + 1][j] == 'M')
                res++;
            if (j + 1 < cols && b[i + 1][j + 1] == 'M')
                res++;
        }
        if (j - 1 >= 0 && b[i][j - 1] == 'M')
            res++;
        if (j + 1 < cols && b[i][j + 1] == 'M')
            res++;
        return res;
    }
}
```