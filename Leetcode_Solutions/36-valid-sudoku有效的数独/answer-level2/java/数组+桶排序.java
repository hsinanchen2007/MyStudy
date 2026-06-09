### 解题思路
利用桶排序的思想

### 代码

```java
class Solution {
  public boolean isValidSudoku(char[][] board) {
      
      int[][] rows = new int[9][9];
      int[][] columns = new int[9][9];
      int[][] boxs = new int[9][9];
      
        for(int i = 0; i < 9; i ++){
        // hori, veti, sqre分别表示行、列、小宫
      
        for(int j = 0; j < 9; j ++){
            // 由于传入为char，需要转换为int，减48
           
            if(board[i][j]>='0'&&board[i][j]<='9'){
            
            int n = board[i][j]-'0';
            if((rows[i][n-1]==1||columns[j][n-1]==1||boxs[(i / 3 ) * 3 + j / 3][n-1]==1))return false;
            
            rows[i][n-1]=1;
            columns[j][n-1]=1;
            boxs[(i / 3 ) * 3 + j / 3][n-1]=1;
            
            }
            
            
        }
    }
    return true;
}




}
```