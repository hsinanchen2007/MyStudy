### 解题思路

 用了遍历的方法，找到一个1后，认为找到了一个岛屿，然后 将其值置为2，再从这个点查找周围的1，找到全部置2.
### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        if(grid==null){
            return 0;
        }
        int count = 0;
        int columnNum = grid.length;
        for(int i=0;i<columnNum;i++){
            //每一行
            char[] row = grid[i];
            int rowNum = row.length;
            for(int j=0;j<rowNum;j++){
                //每一个
                char value = row[j];
                if(value=='1'){
                    count++;
                    inject(grid,i,j);
                }
            }
        }
        return count;
    }
    public void inject(char[][] grid,int i, int j){
        grid[i][j]='2';
        if(i>=1 && grid[i-1][j]=='1'){
            inject(grid,i-1,j);
        }
        if(i<grid.length-1 && grid[i+1][j]=='1'){
            inject(grid,i+1,j);
        }
        if(j>=1 && grid[i][j-1]=='1'){
            inject(grid,i,j-1);
        }
        if(j<grid[i].length -1 && grid[i][j+1]=='1' ){
            inject(grid,i,j+1);
        }
    }
}
```