### 解题思路
使用回溯法，以一行为单位进行回溯，排列所有组合。

### 代码

```java
class Solution {
    // private boolean[] rowUsed; // 一行放一个，所以不需要
    private boolean[] colUsed;
    private boolean[] diagonal45Used;
    private boolean[] diagonal135Used;
    private List<List<String>> res;
    private int n;
    private char[][] nQueens;   //初始化为'.'
    public List<List<String>> solveNQueens(int n) {
        res=new ArrayList<>();
        this.n=n;
        colUsed=new boolean[n];
        diagonal45Used=new boolean[2*n-1];
        diagonal135Used=new boolean[2*n-1];;
        nQueens=new char[n][n];
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++) nQueens[row][col]='.';
        }
        backTracking(0);
        return res;

    }

    private void backTracking(int row){
        if (row==n){
            List<String> list=new ArrayList<>();
            for (char [] chars :nQueens){
                list.add(new String(chars));
            }
            res.add(list);
            return;}
        for(int col=0;col<n;col++){
            int diagonal45UsedNum=getDiagonal45UsedNum(row,col);
            int diagonal135UsedNum=getDiagonal135UsedNum(row,col);
            if(colUsed[col]||diagonal45Used[diagonal45UsedNum]||diagonal135Used[diagonal135UsedNum]) continue;
            colUsed[col]=diagonal45Used[diagonal45UsedNum]=diagonal135Used[diagonal135UsedNum]=true;
            nQueens[row][col]='Q';
            backTracking(row+1);
            nQueens[row][col]='.';
            colUsed[col]=diagonal45Used[diagonal45UsedNum]=diagonal135Used[diagonal135UsedNum]=false;
        }
    }

    private int getDiagonal45UsedNum(int row,int col){
        return row+col;
    }
    private int getDiagonal135UsedNum(int row,int col){
        return n-1-(row-col);
    }
}
```
执行用时 :2 ms, 在所有 Java 提交中击败了99.62%的用户
内存消耗 :41.3 MB, 在所有 Java 提交中击败了6.25%的用户