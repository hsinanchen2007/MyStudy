
![leetcode_result64.png](https://pic.leetcode-cn.com/3c3d0ab38ee7096866999e7a7c32255befc06ebc46c7a2881572c69c32fad441-leetcode_result64.png)
### 解题思路
相信机器人走路那题会的，这题也不难，无非就是增加一个求和;
大体思路很简单：
由于只能向下和向右走，那么反推回来，最右下的点的最小路径和就等于其点数加上min(其左边的最小路径和,其上边的最小路径和），用代码表示即：
minsum[i][j]=grid[i][j]+Math.min(minsum[i][j-1],minsum[i-1][j]);
如果到了第0行，由于只能向右或者向下走，所以第0行上的点的最小路径和就等于该行上从第0列到该点的所有数之和，即：
minsum[0][j]=grid[0][0]+grid[0][1]+....+grid[0][j-1]+grid[0][j];
同理到了第0列，也是该列和，即：
minsum[i][0]=grid[0][0]+grid[1][0]+....+grid[i-1][0]+grid[i][0];
### 代码

```java
class Solution {
    private int ans=0;
    private int[][] minsum;
    private int[][] grid;
    
    private int rowSum(int col)
    {
        int rowsum=0;
        for(int i=0;i<=col;i++)
            rowsum+=grid[0][i];
        return rowsum;
    }
    private int colSum(int row)
    {
        int colsum=0;
        for(int i=0;i<=row;i++)
            colsum+=grid[i][0];
        return colsum;
    }
    private int minSum(int row,int col)
    {
        if(minsum[row][col]!=0)
            return minsum[row][col];
        if(row==0)
        {
            return rowSum(col);
        }
        if(col==0)
        {
            return colSum(row);
        }
        int leftmin=minSum(row,col-1);
        int upmin=minSum(row-1,col);
        minsum[row][col]=Math.min(leftmin, upmin)+grid[row][col];
        return minsum[row][col];
    }
    
    public int minPathSum(int[][] grid) {
        if(grid.length==0)return 0;
        this.grid=grid;
        if(grid.length==1)
            return rowSum(grid[0].length-1);
        if(grid[0].length==1)
            return colSum(grid.length-1);
        minsum=new int[grid.length][grid[0].length];
        return minSum(grid.length-1,grid[0].length-1);
    }
}
```