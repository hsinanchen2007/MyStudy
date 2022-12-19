执行用时 :0 ms, 在所有 Java 提交中击败100.00%的用户
内存消耗 :37.9 MB, 在所有 Java 提交中击败了5.71%的用户

话不多说，上代码

class Solution {
    int[] dr={-1,1,0,0,-1,-1,1,1};
    int[] dc={0,0,-1,1,-1,1,-1,1};
    int mrow;
    int mcol;
    public void gameOfLife(int[][] board) {
        int row = board.length;
        if(row<1) return ;
        int col = board[0].length;

        mrow = row;
        mcol = col;

        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                //活细胞
                if(board[i][j] >=1)
                {
                    liveChange(board,i,j,true);
                }else{  //死细胞
                    liveChange(board,i,j,false);
                }
            }
        }

        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                //活细胞
                if(board[i][j] ==-1)
                {
                    board[i][j] = 1;
                }else if(board[i][j] ==2){  //死细胞
                    board[i][j]=0;
                }
            }
        }
    }
    private void liveChange(int[][] board,int x,int y,boolean isAlive)
    {
        int liveCnt=0;
        for(int i=0;i<8;++i)
        {
            int m = x+dr[i];
            int n = y+dc[i];
            if(m>=0 && m<mrow && n>=0 && n<mcol)
            {
                if(board[m][n] >=1)
                {
                    liveCnt++;
                }
            }
        }
        if(isAlive)
        {
            if(liveCnt<2||liveCnt>3)
            {
                board[x][y] =2; //死亡
            }
        }else{
            if(liveCnt==3)
            {
                board[x][y] =-1;
            }
        }
        
    }
   
}

我采用的方法是不用额外的数组空间。

在遍历过程中，活细胞在这个时刻即使变化，这个变化的影响在当前遍历中也不能起作用，因此不能直接在原数组上将其改变。
但是可以添加两个状态2和-1.
2表示  从活到死
-1表示 从死到活

在第一次遍历中只要是状态大于等于1就算是活得，否则是死的

第二次遍历中，值为2的，更新为0；值为1的，更新为1.

