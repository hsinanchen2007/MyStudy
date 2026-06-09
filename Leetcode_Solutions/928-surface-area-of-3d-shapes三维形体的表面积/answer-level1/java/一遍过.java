### 解题思路
pure math

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
                    surface+=(cur*6-(cur-1)*2);
                }
                if(top>0){
                  surface-=(Math.min(top,cur)*2);  
                }
                if(left>0){
                  surface-=(Math.min(left,cur)*2);  
                }
                
            }
        }
        return surface;
    }
}
```