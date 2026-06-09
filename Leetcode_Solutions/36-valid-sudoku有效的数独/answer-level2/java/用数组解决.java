### 解题思路
只需要用boolean数组进行遍历即可。
### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] pal = new boolean[9][10];
        for(int i=0;i<9;i++){
            boolean[] row = new boolean[10];
            boolean[] col = new boolean[10];
            for(int j=0;j<9;j++){
                int valrow = board[i][j] - '0';
                if(valrow>0){
                    if(row[valrow]){
                        return false;
                    }
                    else{
                        row[valrow]= true;
                    }
                    int r = (i / 3)*3 + (j /3);
                    if(pal[r][valrow]){
                        return false;
                    }
                    else{
                        pal[r][valrow] = true;
                    }
                }
                
                int valcol = board[j][i] - '0';
                if(valcol > 0){
                    if(col[valcol]){
                        return false;
                    }
                    else{
                        col[valcol]= true;
                    }
                }
            }
        }

    return true;
    }
}
```