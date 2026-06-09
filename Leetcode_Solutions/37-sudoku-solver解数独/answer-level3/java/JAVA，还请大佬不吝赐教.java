我本来这么写的
```
public boolean isValidSudoku(char[][] board) {
    Set<Character> set = new HashSet<>();
    for (int i = 0; i <9 ; i++) {
        for (int j = 0; j <9 ; j++) {
            if(board[i][j]!='.' && !set.add(board[i][j]))
                return false;
        }
        set.clear();
    /*}
    for (int i = 0; i <9 ; i++) {*/
        for (int j = 0; j <9 ; j++) {
            if(board[j][i]!='.' && !set.add(board[j][i]))
                return false;
        }
        set.clear();
    /*}
    for (int i = 0; i <9 ; i++) {*/
        int temp = i/3;
        for (int j = 0; j <9 ; j++) {
            if(board[i%3*3+j/3][j%3+temp*3]!='.' && !set.add(board[i%3*3+j/3][j%3+temp*3]))
                return false;
        }
        set.clear();
    }
    return true;
}
```
然后我觉得set不太好
所以我就这么写了
```
public boolean isValidSudoku(char[][] board) {
    for (int i = 0; i <9 ; i++) {
        for (int j = 0; j <9 ; j++) {
            if (board[i][j]!='.')
                for (int k = 0; k <9 ; k++) {
                    if (k!=j && board[i][j]==board[i][k])
                        return false;
                }
        }
    /*}
    for (int i = 0; i <9 ; i++) {*/
        for (int j = 0; j <9 ; j++) {
            if(board[j][i]!='.')
                for (int k = 0; k <9 ; k++) {
                    if (k!=j && board[j][i]==board[k][i])
                        return false;
                }
        }
    /*}
    for (int i = 0; i <9 ; i++) {*/
        int temp = i/3;
        for (int j = 0; j <9 ; j++) {
            if(board[i%3*3+j/3][j%3+temp*3]!='.')
                for (int k = 0; k <9 ; k++) {
                    if (j!=k && board[i%3*3+k/3][k%3+temp*3]==board[i%3*3+j/3][j%3+temp*3])
                        return false;
                }
        }
    }
    return true;
}

```
可是为什么感觉没什么效果，额。。。