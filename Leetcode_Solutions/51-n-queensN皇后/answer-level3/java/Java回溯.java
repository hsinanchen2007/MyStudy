### 解题思路
将一个长度为n*n的char [] 作为棋盘，初始化一个长度为n的数组记录每一列是否有皇后，初始化两个长度为2n-1的数组记录两种对角线上的是否有queen（每一条对角线能够根据当前位置唯一对应到对角线记录数组一个索引）。 

### 代码

```java
class Solution {
    private void nQ_backTrack(char [] board, int [] col_record, int [] diag_record1,int [] diag_record2, int row, int n){
        if (row >= n){
            res12.add(String.valueOf(board));
            return;
        }

        for (int i = 0; i < n; i++){
            int index = row*n+i;
            int col = i;
            int min = Math.min(row, col);
            int x = row - min;
            int y = col - min;
            int diag1 = 0;
            if (x == 0){
                diag1 = n-1+y;
            }
            else{
                diag1 = n-1-x;
            }

            min = Math.min(row, n-1-col);
            x = row - min;
            y = col + min;
            int diag2 = 0;
            if (x==0){
                if (y == n - 1){
                    diag2 = y-x;
                }
                else{
                    diag2 = y+n;
                }
            }
            else{
                diag2 = y - x;
            }
            if (col_record[col] != 1 && diag_record1[diag1] != 1 && diag_record2[diag2] != 1){
                board[index] = 'Q';
                col_record[col] = 1;
                diag_record1[diag1] = 1;
                diag_record2[diag2] = 1;
                nQ_backTrack(board,col_record,diag_record1,diag_record2, row + 1, n);
                board[index] = '.';
                col_record[col] = 0;
                diag_record1[diag1] = 0;
                diag_record2[diag2] = 0;
            }
        }
    }

    List<String> res12 = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        char [] board = new char [n*n];
        Arrays.fill(board, '.');
        int [] col_record = new int [n];
        int [] diag_record1 = new int [2*n-1];
        int [] diag_record2 = new int [2*n-1];
        nQ_backTrack(board, col_record,diag_record1,diag_record2, 0, n);
        List<List<String>> res = new ArrayList<>();
        for (String s : res12){
            List<String> tmp = new ArrayList<>();
            for (int i = 0; i < n*n; i+=n){
               tmp.add(s.substring(i, i+n));
            }
            res.add(tmp);
        }
        return res;
    }
}
```