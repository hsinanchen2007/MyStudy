### 解题思路
先算出一共有多少个小正方体，记作n；
除了第一列每一列每个小正方体与前一列相邻的小正方体个数为m;
除了第一行每一行每个小正方体与前一行相邻小正方体个数为m1;
每个格子正方体相邻个数为grid[i][j]-1;
总表面积公式为n*6-m*2-m1*2-m2*2。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
     int ha=grid.length;//行
        int li=grid[0].length;//列
        int n=0;//小正方体个数
        int m=0;//所有横向重叠的方块个数
        int m1=0;//列项小方块重叠个数
        int m2=0;
        for(int i=0;i<ha;i++){
            for(int j=0;j<li;j++) {
                n+=grid[i][j];
                if (j != 0) {
                    m += Math.min(grid[i][j], grid[i][j - 1]);
                }
                if (grid[i][j] >= 2) {
                    m2 +=(grid[i][j] - 1);
                }
                if (i!=0) {
                    m1 += Math.min(grid[i - 1][j], grid[i][j]);
                }
            }
        }
        return n*6-m*2-m1*2-m2*2;
    }
}
```