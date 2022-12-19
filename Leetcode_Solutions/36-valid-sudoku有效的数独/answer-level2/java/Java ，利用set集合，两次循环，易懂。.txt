```
代码块
 public boolean isValidSudoku(char[][] board) {
        //每一行，每一列，每3*3的小格子，set集合有自动去重的功能。
        //每一行,每一列
        for (int i=0;i<9;i++){
            //每一行生成一个新的set集合
            //保存每一行是否重复的set集合
            Set lineset=new HashSet();
            //保存每一列是否重复的set集合
            Set rowset=new HashSet();
            int linecount=0;//count 记录这一行是数字的个数（不是'.'的个数）
            int rowcount=0;//count 记录这一列是数字的个数
            //遍历数组的行和列
            for (int k=0;k<9;k++){
                if (board[i][k]!='.'){
                    linecount ++;
                    lineset.add(board[i][k]);
                }
                if(board[k][i]!='.'){
                    rowcount++;
                    rowset.add(board[k][i]);
                }
            }
            if (lineset.size()<linecount){
                return false;
            }
            if (rowset.size()<rowcount){
                return false;
            }
        }
        //遍历每个 3*3的小格子
        for(int i=0;i<9;i+=3){
            for(int k=0;k<9;k+=3){
                Set set=new HashSet();
                int count=0;
                for (int m=i;m<i+3;m++){
                    for (int n=k;n<k+3;n++){
                        if (board[m][n]!='.'){
                            count++;
                            set.add(board[m][n]);
                        }
                    }
                }
                if (set.size()<count){
                    return false;
                }
            }
        }
        return true;
    }
```
