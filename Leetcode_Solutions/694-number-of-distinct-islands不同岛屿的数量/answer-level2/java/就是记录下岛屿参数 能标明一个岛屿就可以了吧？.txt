### 解题思路
为了简单 直接记录了岛屿递归时的尝试路径

### 代码

```java
class Solution {
	public int numDistinctIslands(int[][] grid) {
        if(grid==null){
            return 0;
        }
        int columnNums = grid.length;
        ArrayList<String> pathList = new ArrayList<String>();
        int count = 0;
        for(int i=0;i<columnNums;i++){
            int[] row = grid[i];
            for(int j=0;j<row.length;j++){
                if(row[j]==1){
                    String path = "";
                    path = inject(grid,i,j,path);
                    if(!pathList.contains(path)){
                        pathList.add(path);
                        count++;
                    }
                }
            }
        }
        return count;
    }
    public String inject(int[][] grid,int i, int j, String path){
        //上下左右分别是 1 2 3 4 没有上面的 就是 -1 -2 -3 -4
        // 如果两个岛屿尝试的路径一样 那么就是一样的岛屿
        grid[i][j]=0;
        if(i-1>=0 &&grid[i-1][j]==1){
            path +="1";
            path = inject(grid,i-1,j,path);
        }else{
            path+="-1";
        }
        if(i+1<grid.length && grid[i+1][j]==1){
            path += "2";
            path = inject(grid,i+1,j,path);
        }else{
            path+="-2";
        }
        if(j-1>=0 && grid[i][j-1]==1){
            path +="3";
            path = inject(grid,i,j-1,path);
        }else{
            path+="-3";
        }
        if(j+1<grid[0].length && grid[i][j+1]==1){
            path +="4";
            path = inject(grid,i,j+1,path);
        }else{
            path+="-4";
        }
        return path;
    }
}

```