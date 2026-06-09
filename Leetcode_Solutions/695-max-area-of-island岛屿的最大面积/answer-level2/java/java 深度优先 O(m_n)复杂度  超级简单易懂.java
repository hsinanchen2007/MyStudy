### 解题思路
由于对岛屿的形状没有要求，只需按要求找出每一块区域的面积，并比较得出最大值即可，使用深搜方法，为了避免重复搜索相同一块区域，增加一个visited数组记录已经访问过的节点
时间复杂度：O(m*n)  m表示矩形长度，n表示宽度
空间复杂度：O(m*n)  额外的一个数组记录节点是否已访问过
PS:如果要求岛屿是矩形的，那么这种办法就行不通了

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {

       boolean[][] visited = new boolean[grid.length][grid[0].length];
        int max = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
               
                if(grid[i][j] == 1 && !visited[i][j]){
                    max = Math.max(max, dfs(grid, i, j, visited, 0));
                }
            }
        }
        return max;
    }
    private int dfs(int[][] grid, int i, int j, boolean[][] visited, int num){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length) return num;

        if(grid[i][j] == 1 && !visited[i][j]){
            visited[i][j] = true;
            num++;
            num = dfs(grid, i+1, j, visited, num);
            num = dfs(grid, i-1, j, visited, num);
            num = dfs(grid, i, j+1, visited, num);
            num = dfs(grid, i, j-1, visited, num);
        }
        return num;
    }
}
```