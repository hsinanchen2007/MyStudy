### 解题思路
按顺序一行一行看，首先查看数组内每一个格子有多少方块，该格子内贡献了方块数n*4的侧面积加上上下两个表面积。
num += n*4+2
其次同时查看该格子相邻的格子被遮挡的表面积，因为是顺序遍历，我们只查看左边和前面的格子，方便计算，被遮挡的表面积数是两个格子最小方块数的两倍。
num -= min*2
遍历完整个数组之后就计算出总面积数了。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length;
        int num = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                num =num+4*grid[i][j];
                if(grid[i][j]!=0){
                    num += 2;
                }
               if(i!=0){
                   int rowmin = Math.min(grid[i][j],grid[i-1][j]);
                   num -= 2*rowmin;
               }
               if(j!=0){
                   int cowmin = Math.min(grid[i][j],grid[i][j-1]);
                   num -= 2*cowmin;
               } 
            }
        }
        return num;
    }
}
```