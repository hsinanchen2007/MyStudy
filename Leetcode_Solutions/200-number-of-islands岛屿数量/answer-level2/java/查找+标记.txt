### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void search(char[][] grid,int i,int j,int n,int m,int res) {
        //将上、下、左、右为'1'的网格分别同化为自己的标记并继续渗透下去
        if(i-1>=0 && j>=0 && j<m && grid[i-1][j]=='1') {
            grid[i-1][j] += res;
            search(grid,i-1,j,n,m,res);
        }
        if(i+1<n && j>=0 && j<m && grid[i+1][j]=='1') {
            grid[i+1][j] += res;
            search(grid,i+1,j,n,m,res);
        }
        if(j-1>=0 && i>=0 && i<n && grid[i][j-1]=='1') {
            grid[i][j-1] += res;
            search(grid,i,j-1,n,m,res);
        }
        if(j+1<m && i>=0 && i<n && grid[i][j+1]=='1') {
            grid[i][j+1] += res;
            search(grid,i,j+1,n,m,res);
        }
    }
    public int numIslands(char[][] grid) {
        int res = 1;
        if(grid.length==0 || grid[0].length==0) {
            return res-1;
        }
        int n = grid.length;
        int m = grid[0].length;
        int i,j;
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    search(grid,i,j,n,m,res);//第res个被发现的岛屿标记为res
                    res ++;
                }
            }
        }
        return res-1;
    }
}
```