/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/11/7
 * 
 * 解题思路: hash 暴力解决 什么一次遍历的无非是空间换时间 问题不大(由于维数不变 所以时间都是O(1))
 * 
 */
```
public boolean isValidSudoku(char[][] board) {
    int[] hash_row = new int[9];
    int[] hash_col = new int[9];
    int[] hash = new int[9];
    for(int i = 0;i < board.length;i++){
        hash_row = new int[9];
        hash_col = new int[9];
        for(int j = 0;j < board[0].length;j++){
            //检测行
            if(board[i][j] != '.'){
                if(hash_row[board[i][j] - '1'] == 0){
                    hash_row[board[i][j] - '1'] = 1;
                }else{
                    return false;
                }
            }


            //检测列
            if(board[j][i] != '.'){
                if(hash_col[board[j][i] - '1'] == 0){
                    hash_col[board[j][i] - '1'] = 1;
                }else{
                    return false;
                }
            }
        }
    }

    //检测3*3
    for(int i = 0;i < board.length;i+=3){
        for(int j = 0; j < board[0].length;j+=3){
            hash = new int[9];
            for(int m = 0; m < 3;m++){
                for(int n = 0;n < 3;n++){
                    if(board[i+m][j+n] != '.'){
                        if(hash[board[i+m][j+n] - '1'] == 0){
                            hash[board[i+m][j+n] - '1'] = 1;
                        }else {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
```