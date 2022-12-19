### 解题思路
先假设每个坐标点上的格子都是独立，计算面积之后再减去重复的面积
3 ms, 在所有 Java 提交中击败了98.87%的用户
41.7 MB, 在所有 Java 提交中击败了45.48%的用户
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int result=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]!=0)
                    result+=grid[i][j]*4+2;
                if(i>0)
                    if(grid[i-1][j]<=grid[i][j])
                       result-=grid[i-1][j]*2;
                    else
                       result-=grid[i][j]*2;
                if(j>0)
                    if(grid[i][j-1]<=grid[i][j])
                       result-=grid[i][j-1]*2;
                    else
                       result-=grid[i][j]*2; 
            }         
        }
        return result;
    }
}

```