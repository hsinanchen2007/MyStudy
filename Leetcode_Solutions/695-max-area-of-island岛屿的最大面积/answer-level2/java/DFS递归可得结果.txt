### 解题思路
遍历整个矩阵，为1的点向四周进行DFS，一边遍历一边置为0防止重复遍历

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxS = 0 ;
        for(int i =0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[0].length ; j++){
                if(grid[i][j] == 1){
                    maxS = Math.max(DFS(grid,i,j),maxS);
                }
                    // maxS = Math.max(DFS(grid,i,j]),maxS);
            }
        }
        return maxS;
    }

    public int DFS(int[][] grid,int m ,int n){ //计算 grid[m][n]这个岛的大小
        if(m<0 || m>=grid.length || n<0 || n>=grid[0].length )
            return 0;
        if(grid[m][n] == 0)
            return 0;
        grid[m][n] = 0;//清零，防止被重复计算
        int count = 1;
        count += DFS(grid,m+1,n);
        count += DFS(grid,m,n+1);
        count += DFS(grid,m-1,n);
        count += DFS(grid,m,n-1);
        return count;
    }
}
```