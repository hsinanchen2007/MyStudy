### 解题思路
dsf里面，条件判断是否越界，坐标是否为不为0 然后搜索坐标附件位置，把值改为0，只留一个1方便遍历寻找
main方法里面遍历二维数组，找到1就dfs一次，修改坐标点，计数器加一，然后开始下一轮寻找

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int count=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
    public void dfs(char[][] grid,int x,int y){
        if(x<0||y<0||x>=grid.length||y>=grid[0].length||grid[x][y]=='0'){
            return;
        }
        grid[x][y]='0';
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
}
```