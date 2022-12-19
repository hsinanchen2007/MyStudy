如果当前值正确，一次访问它的上下左右
```
class Solution {
    int row;
    int col;
    public boolean exist(char[][] board, String word) {
        row=board.length;
        col=board[0].length;
        boolean res=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int[][] visited=new int[row][col];//标记访问过的位置
                res=search(board,word,visited,i,j,0);
                if(res==true)break;
            }
            if(res==true)break;
        }
        return res;
    }
    public boolean search(char[][] board, String word,int[][] visited,int i,int j,int index){
        //从board[i][j]位置开始找起，判断是否存在
        //从上下左右开始找，还要判断是否在边界处
        if(i<0||i>=row||j<0||j>=col){//如果越界，则退出
            return false;
        }
        //应该自己再生成一个访问矩阵，只记录自己走过的路径
        int[][] newvisited=new int[row][col];
        for(int ii=0;ii<row;ii++){
            for(int jj=0;jj<col;jj++){
                newvisited[ii][jj]=visited[ii][jj];
            }
        }
        if(newvisited[i][j]==1)return false;//如果访问过，则返回错误
        if(board[i][j]==word.charAt(index)){
            if(index==word.length()-1){//如果寻找结束，返回true
                newvisited[i][j]=1;//访问位置1
                return true;
            }else{
                newvisited[i][j]=1;//访问位置1
                return search(board,word,newvisited,i+1,j,index+1)||
                    search(board,word,newvisited,i-1,j,index+1)||
                    search(board,word,newvisited,i,j-1,index+1)||
                    search(board,word,newvisited,i,j+1,index+1);
            }
        }else{
            return false;
        }
    }
}
```
修改后，不适用辅助矩阵，减少空间和时间开销，将访问过的位置置空，访问完后再还原
```
class Solution {
    int row;
    int col;
    public boolean exist(char[][] board, String word) {
        row=board.length;
        col=board[0].length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(search(board,word,i,j,0))return true;
            }
        }
        return false;
    }
    public boolean search(char[][] board, String word,int i,int j,int index){
        //从board[i][j]位置开始找起，判断是否存在
        //从上下左右开始找，还要判断是否在边界处
        if(i<0||i>=row||j<0||j>=col||board[i][j]!=word.charAt(index)){//如果越界，则退出
            return false;
        }
        if(index==word.length()-1)return true;
        char temp=board[i][j];
        board[i][j]='/';
        boolean res=search(board,word,i+1,j,index+1)||search(board,word,i-1,j,index+1)||
                    search(board,word,i,j-1,index+1)||search(board,word,i,j+1,index+1);
        board[i][j]=temp;
        return res;
    }
}
```

