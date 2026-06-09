重叠角度:
组成岛屿的小方格都是四个边,计算有多少个这样的方格
方格和方格之间重叠的部分会隐藏两条边,计算黄色方格
的右边以及下边是否有黄色小方格
land`*`4-overlap`*`2(land代表岛屿小方格数量,overlap代表岛屿与岛屿之间的重叠的个数)
```java
class Solution {
    public int islandPerimeter(int[][] grid) {
         int land=0;
        int overlap=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1){
                    land++;
                    if(j<grid[i].length-1&&grid[i][j+1]==1){
                        overlap++;
                    }
                    if(i<grid.length-1&&grid[i+1][j]==1){
                        overlap++;
                    }
                }

            }
        }
        return land*4-2*overlap;
    }
}
```
边界角度:
   实时考虑遇到一个黄色方格时,左右前后四个方向是否也有黄色小方格或者已经触及边界
   如果已经到达边界或者左右前后都没有岛屿则加起来
```java
class Solution {
     public int islandPerimeter(int[][] grid) {
        int land=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1){

                    if(i-1<0||grid[i-1][j]==0){
                        land++;
                    }
                    if(j-1<0||grid[i][j-1]==0){
                        land++;
                    }
                    if(i==grid.length-1||grid[i+1][j]==0){
                        land++;
                    }
                    if(j==grid[i].length-1||grid[i][j+1]==0){
                        land++;
                    }

                }

            }
        }
        return land;
    }
}

```
