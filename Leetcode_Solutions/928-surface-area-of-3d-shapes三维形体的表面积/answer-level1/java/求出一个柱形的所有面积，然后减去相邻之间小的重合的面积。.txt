### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int col = grid.length;
        int area = 0;
        for(int i=0;i<col;i++){
            for(int j=0;j<col;j++){
                int v = grid[i][j];
                if(v>0){
                    area += v*4 + 2;
                    //减去与右边重合的面积
                    area -=i>0? Math.min(grid[i-1][j],v)*2:0;
                    //减去与下一列重合的面积
                    area -=j>0? Math.min(grid[i][j-1],v)*2:0;
                }
            }
        }
        return area;
    }
}
```