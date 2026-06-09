### 解题思路

不难得出，若四周无其他立方体，则面积公式为 Area=4v+2。

若四周有，则用Area减去两侧较小的V(个数)即可，如与右边的比较：Area-= min(grid[i][j],grid[i][j+1]));

对每个都进行深度优先搜索，用temp数组标记该位置是否已被计算。


### 代码


```java
class Solution {
    public int surfaceArea(int[][]v grid) {
        int surfaceArea = 0;
        int[][] temp = new int[grid.length][grid[0].length];

        for(int i=0;i<temp.length;i++)
            Arrays.fill(temp[i],1);

        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                surfaceArea+=roundArea(grid,temp,i,j);
            }
        }
        return surfaceArea;
    }


    public static int roundArea(int[][] grid,int[][] temp,int i,int j){
        if(temp[i][j]==0) return 0;
        temp[i][j]=0;
        if(grid[i][j]==0) return 0;
        int Area = 4*grid[i][j]+2;

        //上
        if(i>0&&grid[i-1][j]>0){
            Area-=Math.min(grid[i][j],grid[i-1][j]);
            Area+=roundArea(grid,temp,i-1,j);
        }
        //下
        if(i<grid.length-1&&grid[i+1][j]>0){
            Area-=Math.min(grid[i][j],grid[i+1][j]);
            Area+=roundArea(grid,temp,i+1,j);
        }
        //左
        if(j>0&&grid[i][j-1]>0){
            Area-=Math.min(grid[i][j],grid[i][j-1]);
            Area+=roundArea(grid,temp,i,j-1);
        }
        //右
        if(j<grid[0].length-1&&grid[i][j+1]>0){
            Area-=Math.min(grid[i][j],grid[i][j+1]);
            Area+=roundArea(grid,temp,i,j+1);
        }

        return Area;
    }
}
```
![微信图片_20200325125009.png](https://pic.leetcode-cn.com/12ce285a201fd9586e43cdfd0b5935b2fbbcfa059588392a8dd90a72f0318f22-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200325125009.png)