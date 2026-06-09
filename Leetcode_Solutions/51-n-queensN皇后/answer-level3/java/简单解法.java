```
class Solution {
    //用位运算查看当前的可用位置，这里有一个小难点就是如何确定当前行选了哪一列，然后映射到棋盘上
    //方法1,用一个二进制数,这个数只包含一个1,然后依次左移，去判断当前位置是否可用,进而确定是否继续深搜
    //方法2,根据当前行的所有可用列,也就是freeCol,依次找到它的最右边一个1,去深搜,可如何知道最右边的1是
    //代表棋盘上的第几列呢?可以用对数方法log2N,来求得是第几列,只不过java中，不支持log2,需要用自己稍微改写一下
    //执行用时 :2 ms, 在所有 Java 提交中击败了100.00%的用户
    //内存消耗 :37 MB, 在所有 Java 提交中击败了100.00%的用户
    
    List<List<String>> res;
    List<String> item;
    char[][] board;
    public List<List<String>> solveNQueens(int n) {
        res = new ArrayList<>();
        item = new ArrayList<>();
        board = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');

        }
        int col = n == 32 ? -1 : (1 << n) - 1;
        dfs(col, 0, 0, 0, 0, n);
        return res;
    }
    
    //方法1：
    public void dfs(int col, int colLim, int leftLim, int rightLim, int row, int n) {
        if(col == colLim) {
            res.add(new ArrayList<>(item));
        }

        int freeCol = col & (~(colLim | leftLim | rightLim));
        int pos = 1;
        for (int i = n - 1; i >= 0; i--) {
            if ((pos & freeCol) != 0) {
                board[row][i] = 'Q';
                item.add(new String(board[row]));
                dfs(col, colLim | pos, (leftLim | pos) << 1, (rightLim | pos) >> 1, row + 1, n);
                board[row][i] = '.';
                item.remove(item.size() - 1);
            }
            pos <<= 1;
        }
    }
    
//方法2：
      public void dfs(int col, int colLim, int leftLim, int rightLim, int row, int n) {
        if(col == colLim) {
            res.add(new ArrayList<>(item));
        }

        int freeCol = col & (~(colLim | leftLim | rightLim));
        while(freeCol != 0) {
            int mostRight = -freeCol & freeCol;
            int index = n - log2(mostRight) - 1;
            board[row][index] = 'Q';
            item.add(new String(board[row]));
            dfs(col, colLim | mostRight, (leftLim | mostRight) << 1, (rightLim | mostRight) >> 1, row + 1, n);
            freeCol ^= mostRight;
            board[row][index] = '.';
            item.remove(item.size() - 1);
        }
    }

    public int log2(double val) {
        return (int)(Math.log(val) / Math.log(2));
    }
    
    
}
```
