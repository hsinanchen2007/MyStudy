### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        if( grid == null || grid.length<1 || grid[0].length<1){
            return 0;
        }
        int blocks = 0;
        int cover = 0;
        for(int i=0;i<grid.length;i++){
            for(int j =0;j<grid[0].length;j++){
                blocks += grid[i][j];
                cover += grid[i][j] > 1 ? grid[i][j]-1:0;
                if(i>0){
                    cover += Math.min(grid[i-1][j],grid[i][j]);
                }
                if(j>0){
                    cover += Math.min(grid[i][j-1],grid[i][j]);
                }
            }
        }
        return blocks * 6 - cover *2;
    }
}
```