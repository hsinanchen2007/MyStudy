### 解题思路
位操作可以把速度从 4ms->3ms

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int rows = grid.length;
        if(rows == 0){
            return 0;
        }
        int surface = 0;
        //不可能为0
        int cols = grid[0].length;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int cur = grid[i][j];
                int top = (i==0?0:grid[i-1][j]);
                int left = (j==0?0:grid[i][j-1]);
                if(cur>0){
                    surface += (cur << 2)+2;
                    if(top>0){
                        surface-=(Math.min(top,cur)<<1);  
                    }
                    if(left>0){
                        surface-=(Math.min(left,cur)<<1);  
                    }
                }
                
                
            }
        }
        return surface;
    }
}
```