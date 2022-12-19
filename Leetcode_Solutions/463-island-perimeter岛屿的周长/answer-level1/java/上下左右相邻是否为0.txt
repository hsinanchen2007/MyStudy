### 解题思路
求出当前节点的上下左右节点是否为0 ；不过这里要考虑到边界情况：即上下为临界时要加1 ；左右为临界时要加1；

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int perimerter = 0 ;
        for (int i = 0 ; i < grid.length ; i++ ){
            for (int j = 0 ; j < grid[i].length ; j++ ){
                if (grid[i][j] == 1){
                    if (j - 1 < 0 || grid[i][j - 1] == 0) perimerter++ ;
                    if (j + 1 >= grid[i].length || grid[i][j + 1] == 0) perimerter++ ;
                    if (i - 1 < 0 || grid[i - 1][j] == 0) perimerter++;
                    if (i + 1 >= grid.length || grid[i + 1][j] == 0) perimerter++ ;
                }
            }
        }
        return perimerter;
    }
}
```