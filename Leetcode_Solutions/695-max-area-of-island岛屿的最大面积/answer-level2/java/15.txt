### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int m=grid.length-1;
        int n=grid[0].length-1;
        int res=0;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=infect(grid,i,j,m,n);
                    res=res>temp?res:temp;
                }
            }
        }
        return res;
    }

    public int infect(int[][] grid,int i,int j,int m,int n)
    {
        int res=0;
        if(i<0||j<0||i>m||j>n||grid[i][j]!=1)
        {
            return 0;
        }
        grid[i][j]=2;
        res=1+infect(grid,i+1,j,m,n)+infect(grid,i-1,j,m,n)+infect(grid,i,j+1,m,n)+infect(grid,i,j-1,m,n);
        return res;
    } 

}
```