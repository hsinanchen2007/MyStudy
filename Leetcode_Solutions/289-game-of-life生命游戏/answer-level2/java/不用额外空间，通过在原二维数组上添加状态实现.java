### 解题思路
设置两个状态2和-1
在第一次遍历中
2表示 由活到死
-1表示 由死到活

为了让此次更新结果不影响这次遍历，因此大于等于1的状态是活，其他是死

第二次更新这个数组的时候，把2更新为0，-1更新为1就好了

### 代码

```java
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
```