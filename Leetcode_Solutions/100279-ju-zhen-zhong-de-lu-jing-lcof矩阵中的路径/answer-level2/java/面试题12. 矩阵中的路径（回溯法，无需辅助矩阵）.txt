### 解题思路
主要采用回溯的思想，回溯方法为递归，不采用布尔型辅助矩阵来标记格子是否访问，采用一个中间变量字符c来做标记（‘！’），详细解大看注释

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {

        if(board.length==0||word.length()==0)return false;//判断空值条件

        int rows=board.length;
        int cols=board[0].length;
        /**
        boolean[][] visited=new boolean[rows][cols];
        for(int i=0;i<rows;i++){//布尔值的标记矩阵
            for(int j=0;j<cols;j++){
                visited[i][j]=false;
            }
        }
         **/
        int pathLength=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(board[row][col]==word.charAt(pathLength)){
                    if (word.length()==1)return true;//如果长度为1直接为true
                    if(existCore(board,rows,cols,row,col,word,pathLength))return true;
                }
            }
        }
        return false;
    }

    private boolean existCore(char[][] board,int rows,int cols,int row,int col,String word,int pathLength){
        if(!(row>=0&&row<rows&&col>=0&&col<cols))return false;
        if(word.length()==pathLength){//判断字符串是否读完，读完为true
            return true;
        }
        else if(board[row][col]!=word.charAt(pathLength)||board[row][col]=='！')return false;//退出函数条件，如果不匹配就退出，此处借助一个！来标记是否走过该格子
        char c=board[row][col];//将矩阵的当前字符存入C，以便退回
        board[row][col]='!';
        
        if((existCore(board,rows,cols,row+1,col,word,pathLength+1)||existCore(board,rows,cols,row-1,col,word,pathLength+1)||existCore(board,rows,cols,row,col+1,word,pathLength+1)||existCore(board,rows,cols,row,col-1,word,pathLength+1)))    return true;
 
        board[row][col]=c;//没找到就退回
        return false;
    }
}
```