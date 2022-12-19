### 解题思路
1.计算所有柱体面积
2.减去x轴方向相交的面的面积
3.减去y轴方向相交的面的面积

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int ans = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j]!=0)
                    ans += 4*grid[i][j] + 2;
            }
        }
        int xSub = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length-1; j++){
                xSub += 2 * Math.min(grid[i][j], grid[i][j+1]);
            }
        }
        int ySub = 0;
        for(int j=0; j<grid[0].length; j++){
            for(int i=0; i<grid.length-1; i++){
                ySub += 2 * Math.min(grid[i][j], grid[i+1][j]);
            }
        }
        return ans - xSub - ySub;
    }
}
```