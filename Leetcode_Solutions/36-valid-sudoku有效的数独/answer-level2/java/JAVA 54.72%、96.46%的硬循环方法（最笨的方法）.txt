根据题目要求只需要满足行、列、3x3的方格中不存在重复的1-9的数字即可。那么制作3个双重循环，任意一个循环发现重复数字就直接返回false。每次的重复数字判断使用一个set集合，循环开始时将上次的set集合清空重复利用。
```
public boolean isValidSudoku(char[][] board) {
        int i,j;
        Set<Character> set = new HashSet();
        for (i=0;i<board.length;i++){
            set.clear();
            for (j=0;j<board[i].length;j++){
                if (board[i][j] != '.' && set.contains(board[i][j]))
                    return false;
                if (board[i][j] != '.' && !set.contains(board[i][j])){
                    set.add(board[i][j]);
                }
            }
        }
        set.clear();
        for (j=0;j<board[0].length;j++){
            set.clear();
            for (i=0;i<board.length;i++){
                if (board[i][j] != '.' && set.contains(board[i][j]))
                    return false;
                if (board[i][j] != '.' && !set.contains(board[i][j])){
                    set.add(board[i][j]);
                }
            }
        }
        set.clear();
        for (i=0;i<=6;i += 3){
            for (j=0;j<=6;j += 3){
                boolean findtruemath = findtruemath(i, j, board);
                if (!findtruemath)
                    return false;
            }
        }
        return true;
    }
    public boolean findtruemath(int a,int b , char[][] board) {
        int i, j;
        Set<Character> set = new HashSet();
        for (i = a; i < a + 3; i++) {
            for (j = b; j < b + 3; j++) {
                if (board[i][j] != '.' && set.contains(board[i][j]))
                    return false;
                if (board[i][j] != '.' && !set.contains(board[i][j])) {
                    set.add(board[i][j]);
                }
            }
        }
        return true;
    }
```
