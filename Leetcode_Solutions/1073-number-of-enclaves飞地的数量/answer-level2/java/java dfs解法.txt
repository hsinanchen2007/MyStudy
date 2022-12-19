找到所有与边界1连接的1，将其值更改为-1，然后再遍历一次数组，去统计其他1的数量
```java
class Solution {
    int[][]A;
    int rows;
    int columns;
    public int numEnclaves(int[][] A) {
        //找到所有与边界1连接的1，统计其他1的数量
        this.A = A;
        int numbers = 0;
        if(A==null||A.length==0)
            return 0;
        rows = A.length;
        columns = A[0].length;
        //第一列和最后一列
        for(int i=0;i<rows;i++)
        {
            dfs(i,0);
            dfs(i,columns-1);
        }
        //第一行和最后一行
        for(int j=0;j<columns;j++)
        {
            dfs(0,j);
            dfs(rows-1,j);
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
               if(A[i][j]==1)
                   numbers++;
            }
        }
        return numbers;
    }
    public void dfs(int i,int j)
    {
        if(i<0||i>=rows||j<0||j>=columns||A[i][j]==0||A[i][j]==-1)
            return;
        A[i][j]=-1;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
}
```
