### 解题思路
通过回溯法来解决问题
* 每一行，每一列，每一斜向都只能有一个Queen
* 我们在每一行只放入一个Queen,可以使我们的限制变少，只需要考虑列和斜向的限制
* 斜向数组长度为(2n-1)，我们可以为它定义一个顺序(左下->右上，左上->右下)

### 执行结果
执行用时 :2 ms, 在所有 Java 提交中击败了99.74%的用户<br>
内存消耗 :41.6 MB, 在所有 Java 提交中击败了5.02%的用户

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> list = new ArrayList<>();
        
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        boolean[] colUsed = new boolean[n];
        boolean[] line45Used = new boolean[2*n-1];
        boolean[] line135Used = new boolean[2*n-1];
        nQueen(board, 0, list, colUsed, line45Used, line135Used);

        return list;
    }

    private void nQueen(char[][] board, int r, List<List<String>> list,
    boolean[] colUsed, boolean[] line45Used, boolean[] line135Used){
        int n = board.length;
        //如果r >= n 则代表我们已经完成了n皇后的排列
        if(r >= n){
            List<String> inner = new ArrayList<String>();
            for(char[] chars : board){
                inner.add(String.valueOf(chars));
            }
            list.add(inner);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!colUsed[i] && !line45Used[i+r] && !line135Used[i-r+n-1]){
                board[i][r] = 'Q';
                colUsed[i] = true;
                line45Used[i+r] = true;
                line135Used[i-r+n-1] = true;
                //回溯
                nQueen(board, r+1, list, colUsed, line45Used, line135Used);
                colUsed[i] = false;
                line45Used[i+r] = false;
                line135Used[i-r+n-1] = false;
                board[i][r] = '.';
            }
        }
    }
}
```