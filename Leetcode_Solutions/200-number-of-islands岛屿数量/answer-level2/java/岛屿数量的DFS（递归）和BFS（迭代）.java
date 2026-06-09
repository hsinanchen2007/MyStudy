### 解题思路
递归：深度优先算法（DFS），遇到1，就将岛屿数量加一，同时访问周边是否相邻的1，如果遇到联通的1就置为0，这样，就不导致重复计算
迭代：广度优先算法（BFS）,使用队列保存四个方向四个点处的坐标，判断是否是1

递归的解法如果想用迭代的方法解决，最常用的办法是借助队列或者堆栈解决
DFS的迭代应该可以采用堆栈来解决，没有仔细考虑
### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int num = 0;
        for(int i=0;i<grid.length;i++)
            for(int j =0;j<grid[i].length;j++){
                if(grid[i][j]=='1'){
                    num++;
                    dfs(i,j,grid);
                }  
            }
        return num;
    }
    public void dfs(int i,int j,char[][]grid){
        if(grid[i][j]=='1'){
            grid[i][j] = '0';
            if(i+1<grid.length)
                dfs(i+1,j,grid);
            if(j+1<grid[i].length)
                dfs(i,j+1,grid);
            if(i>=1)
                dfs(i-1,j,grid);
            if(j>=1)
                dfs(i,j-1,grid);
        }else return;
    }
}
```