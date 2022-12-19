### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean [][] row=new boolean[9][9];
        boolean [][] col=new boolean[9][9];
        boolean [][] bloc=new boolean[9][9];
        for(int i = 0; i < 9; i++){
          for(int j = 0; j < 9; j++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'1';
                int blockindex=i/3*3+j/3;
                if(row[i][num] || col[j][num] || bloc[blockindex][num]){
                    return false;
                }else{
                    row[i][num]=true;
                    col[j][num]=true;
                    bloc[blockindex][num]=true;
                }
            }
         }
        }
        return true;
    }
}
```