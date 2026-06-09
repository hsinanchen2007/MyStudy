### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length,area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //先把grid[i][j]赋值给level,省掉了bound check 
                int level = grid[i][j];
                if(level > 0){
                    //一个柱体中：2个底面++所有的正方体
                    area += (level << 2) + 2;
                    //减掉i 与i -1 相贴的两份表面积
                    area -= i > 0 ? Math.min(level,grid[i-1][j]) << 1:0;
                    //剪掉J与j-1相贴的两份表面积
                    area -= j>0 ? Math.min(level,grid[i][j-1])<<1:0;
                }
            }
        }
        return area;

    }
}
```