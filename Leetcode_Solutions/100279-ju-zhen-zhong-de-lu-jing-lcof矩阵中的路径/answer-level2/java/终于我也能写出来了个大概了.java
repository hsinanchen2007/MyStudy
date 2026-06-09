### 解题思路
这一题是用深度优先搜索来解，就是说遇到这种题，不要慌。毕竟我大致的框架可以写出来。
首先边界条件，先怼上。
接着获取数组的行数和列数，定义ans
接着开始写个双重循环

接下来进入重头戏，处理递归函数。
递归函数的出口先怼上，
	先写上啥时候我们直接return false。
	再写上，我们啥时候return true。
此处有个要点题目中又说道，字母不可以被重复使用。
	因此我们可以先将board位置的字符暂存一下，置为0，在递归调用完了之后再恢复回去，以供下次调用。
递归调用
	就是从当前坐标的上下左右四个方向去找有没有符合条件的。如果有那么继续递归调用，直到index的长度==word.length()-1，这时可以返回true了。如果没有则返回false。
最后return 递归调用的结果

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board==null || board.length==0 || board[0].length==0) {
            return false;
        }
        int n = board.length;
        int m = board[0].length;
        boolean ans = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = ans || helper(board, word, 0, i, j);
            }
        }
        return ans;

    }
    private boolean helper(char[][] board, String word, int index, int i, int j) {
        if(i<0 || i>=board.length || j<0 || j>=board[0].length || board[i][j]!=word.charAt(index)) {
            return false;
        }
        if(index==word.length()-1) {
            return true;
        }
        char cur = board[i][j];
        board[i][j] = 0;
        boolean found = helper(board, word, index+1, i-1, j) ||
                helper(board, word, index+1, i+1, j) ||
                helper(board, word, index+1, i, j-1) ||
                helper(board, word, index+1, i, j+1);
        board[i][j] = cur;
        return found;
    }
}
```