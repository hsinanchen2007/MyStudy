### 解题思路
用一个比board更大的board1去做判断，结果传回给board。

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] board1 = new int[board.length+2][board[0].length+2];
        for(int i=0;i<board.length+2;i++)
        {
            for(int j=0;j<board[0].length+2;j++)
            {
                if(i==0 || i==board.length+1 || j==0 || j==board[0].length+1)
                {
                    board1[i][j] = -1;
                }
                else{
                    board1[i][j] = board[i-1][j-1];
                }
            }
        }
        for(int i=1;i<board.length+1;i++)
        {
            for(int j=1;j<board[0].length+1;j++)
            {
                board[i-1][j-1] = surroundingCeil(board1 , i , j);
            }
        }
    }
    int surroundingCeil(int[][] board1,int i,int j)
    {
        int cnt0 = 0,cnt1 = 0;
        for(int a=i-1;a<=i+1;a++)
        {
            for(int b=j-1;b<=j+1;b++)
            {
                if(a==i && b==j)
                {
                    continue;
                }
                if(board1[a][b]==0)
                {
                    cnt0++;
                }
                else if(board1[a][b]==1)
                {
                    cnt1++;
                }
            }
        }
        if(board1[i][j]==1 && (cnt1<2 || cnt1>3))
        {
            return 0;
        }
        if(board1[i][j]==0 && cnt1==3)
        {
            return 1;
        }
        return board1[i][j];
    }
}
```