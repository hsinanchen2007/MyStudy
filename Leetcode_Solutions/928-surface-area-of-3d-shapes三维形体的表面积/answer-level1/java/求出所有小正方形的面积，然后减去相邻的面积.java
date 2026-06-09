### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int sum = 0;
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                sum+=grid[i][j]*6;
            }
        }
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j]>=1) sum=sum -(grid[i][j]-1)*2;
                if(i-1>=0){
                    int a = grid[i-1][j]>=grid[i][j]?grid[i][j]:grid[i-1][j];
                    sum =sum- a*2;
                }
                if(j-1>=0){
                    int b = grid[i][j-1]>=grid[i][j]?grid[i][j]:grid[i][j-1];
                    sum =sum- b*2;
                }

            }

        }

        return sum;
    }
}
```