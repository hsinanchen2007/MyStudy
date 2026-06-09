### 解题思路
先找到白车位置，然后上下左右遍历数组直到找到黑卒，但是一个方向一个递归写的太累赘了，应该可以优化成一个递归，但还没想到怎么做，不知道有没有大佬可以给个建议oVo

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {

        //确定是否有白车,有则求白车坐标
        boolean falg = false;
        int h = 0;
        int l = 0;
        //白车能抓到的黑卒数
        int sum = 0;

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    falg = true;
                    //上下左右递归查找是否有黑卒
                    sum += dfs1(board, i + 1, j); //下
                    sum += dfs2(board, i - 1, j);//上
                    sum += dfs3(board, i, j + 1);//右
                    sum += dfs4(board, i, j - 1);//左
                    // System.out.println(i);
                    // System.out.println(j);


                }
            }

        }

        if (!falg) return 0;

        return sum;
    }


    public int dfs1(char[][] board, int i, int j) {
        int sum = 0;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length ||
                board[i][j] == 'B' || board[i][j] == 'P' || board[i][j] == 'r' || board[i][j] == 'b') {
            return 0;
        }

        if (board[i][j] == 'p') return 1;

        sum += dfs1(board, i + 1, j); //下
        //sum += dfs(board, i - 1, j);//上
        //sum += dfs(board, i, j + 1);//右
        //sum += dfs(board, i, j - 1);//左

        return sum;
    }

    public int dfs2(char[][] board, int i, int j) {
        int sum = 0;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length ||
                board[i][j] == 'B' || board[i][j] == 'P' || board[i][j] == 'r' || board[i][j] == 'b') {
            return 0;
        }

        if (board[i][j] == 'p') return 1;

        //sum += dfs(board, i + 1, j); //下
        sum += dfs2(board, i - 1, j);//上
        // sum += dfs(board, i, j + 1);//右
        // sum += dfs(board, i, j - 1);//左

        return sum;
    }


    public int dfs3(char[][] board, int i, int j) {
        int sum = 0;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length ||
                board[i][j] == 'B' || board[i][j] == 'P' || board[i][j] == 'r' || board[i][j] == 'b') {
            return 0;
        }

        if (board[i][j] == 'p') return 1;

        //sum += dfs(board, i + 1, j); //下
        // sum += dfs(board, i - 1, j);//上
        sum += dfs3(board, i, j + 1);//右
        //sum += dfs(board, i, j - 1);//左

        return sum;
    }


    public int dfs4(char[][] board, int i, int j) {
        int sum = 0;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length ||
                board[i][j] == 'B' || board[i][j] == 'P' || board[i][j] == 'r' || board[i][j] == 'b') {
            return 0;
        }

        if (board[i][j] == 'p') return 1;

        //sum += dfs(board, i + 1, j); //下
        // sum += dfs(board, i - 1, j);//上
        //sum += dfs(board, i, j + 1);//右
        sum += dfs4(board, i, j - 1);//左

        return sum;
    }
}
```