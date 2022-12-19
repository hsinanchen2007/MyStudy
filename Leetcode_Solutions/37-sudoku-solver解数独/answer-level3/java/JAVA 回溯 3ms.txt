### 解题思路
思路很简单，定义三组boolean[9][10]标记，分别记录行、列、单元的数组是否被使用，1-9逐个实验即可。
backTracking如何中止思考了一会，最后使用boolean变量查看是否中止递归（void回溯写多了一开始没想起来-，-）。

### 代码

```java
class Solution {
    private boolean[][] rowsUsed = new boolean[9][10];  //10便于计算
    private boolean[][] colsUsed = new boolean[9][10];
    private boolean[][] cubesUsed = new boolean[9][10];
    private char[][] board;
    public void solveSudoku(char[][] board) {
        this.board=board;
        maskUsed();
        backTracking(0,0);
    }
    private boolean backTracking(int row,int col){
        while(row<9 &&board[row][col]!='.'){ //判断需要补充数字的位置
            row=col==8? row+1:row;
            col=col==8? 0:col+1;
        }
        if (row==9) return true;
        for(int num=1;num<=9;num++){  // 填数
            if(rowsUsed[row][num]||colsUsed[col][num]||cubesUsed[cubeNum(row,col)][num]) continue;  //存在重复
            maskTF(row,col,num,true);
            board[row][col]=(char)(num+'0');
            if (backTracking(row,col)) return true;
            maskTF(row,col,num,false);
            board[row][col]='.';
        }
        return false;
    }
    //标记T/F
    private void maskTF(int row,int col,int val, boolean bool){
        rowsUsed[row][val]=bool;
        colsUsed[col][val]=bool;
        cubesUsed[cubeNum(row,col)][val]=bool;
    }

    // 标记已有数字
    private void maskUsed(){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]!='.'){
                    int val=board[row][col]-'0';
                    rowsUsed[row][val]=true;
                    colsUsed[col][val]=true;
                    cubesUsed[cubeNum(row,col)][val]=true;
                }
            }
        }
    }
    // 获得3*3宫编号
    private int cubeNum(int row,int col){
        return row/3*3+col/3;
    }
}
```

执行用时 :3 ms, 在所有 Java 提交中击败了95.35%的用户
内存消耗 :36.7 MB, 在所有 Java 提交中击败了19.23%的用户