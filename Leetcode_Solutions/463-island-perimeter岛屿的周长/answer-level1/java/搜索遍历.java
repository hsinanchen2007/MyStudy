### 解题思路
遍历每一个为1 的小块，查找与其相邻的1块儿的个数，注意边界处理条件

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid == null) return 0;
        int sum = 0;
        int row = grid.length;
        int col = grid[0].length;
        
        for(int j=0; j < col; j++){
            for(int i=0; i < row; i++){
                if(grid[i][j] == 1){
                    sum += 4;
                    if(i > 0 && grid[i-1][j] == 1)
                        sum -= 1;
                    if(j > 0 && grid[i][j-1] == 1)
                        sum -= 1;
                    if(i < row-1 && grid[i+1][j] == 1)
                        sum -= 1;
                    if(j < col-1 && grid[i][j+1] == 1)
                        sum -= 1;
                }
            }
        }
        return sum;

    }
}
```