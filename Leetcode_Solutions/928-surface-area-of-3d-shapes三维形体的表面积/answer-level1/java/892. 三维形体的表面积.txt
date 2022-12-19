### 解题思路
参考的这位大佬的  https://leetcode-cn.com/problems/surface-area-of-3d-shapes/solution/shi-li-you-tu-you-zhen-xiang-jiang-jie-yi-kan-jiu-/
每一个坐标上的立方体的面积值为 4*个数+2
每次相加是减去重叠的面积 Math.min(grid[i-1][j],level)*2 和 Math.min(grid[i][j-1],level)*2
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int len=grid.length;
        int area=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                int level=grid[i][j];
                if(level>0){
                    area+=level*4+2;
                    if(i>0){
                        area-=Math.min(level,grid[i-1][j])*2;
                    }
                    if(j>0){
                      area-=Math.min(level,grid[i][j-1])*2;
                    }
                }
                
            }
        }

        return area;
    }
}
```