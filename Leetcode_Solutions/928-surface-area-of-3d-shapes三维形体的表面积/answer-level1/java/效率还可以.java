### 
就是减去重合面呀

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        
        if(grid.length == 0 || grid[0].length == 0)return 0;
        int n = grid.length;        
        int i = 0, j = 0;
        int sum = n * n * 2;
        //先把只有上下重合面的情况下的总数求一下
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 0)sum -= 2;
                else sum += (grid[x][y] * 4);
            }
        }
        //设置一个数代表两个小正方体之间重合的面的个数
        int h = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(y < n-1) h = h + Math.min(grid[x][y], grid[x][y + 1]);
                if(x < n-1) h = h + Math.min(grid[x][y], grid[x + 1][y]);
            }        
        }
        return sum-h*2;      
    }
}
```