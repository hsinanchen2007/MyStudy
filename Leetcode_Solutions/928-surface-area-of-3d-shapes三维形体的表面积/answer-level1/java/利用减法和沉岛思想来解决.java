### 解题思路
一开始想过使用加法解决，但想了一下加法有些复杂。
而减法就简单了，我只需要求出所有的面积减去相邻的面积。
我把每个位置上的立方体看成一个整体，先求出每个位置上的立方体叠加起来的表面积，比如[[1,2],[3,4]]，在grid[0][0]上有一个正方体，表面积为6，grid[0][1]上有2个正方体，表面积为10，grid[1][0]上有3个正方体，表面积为14，grid[1][1]上有4个正方体，表面积为18，总的表面积为48.
然后减去柱体相邻的面积，比如grid[0][0]和grid[0][1]相邻，且相邻面积为高度矮的那个，就在总面积上减去min(grid[0][0],grid[0][1])*2，依次类推。
但是有个问题是可能会出现重复相减的情况，他们使用的是规定减的方向，比如从左上角开始只减右边和下边的。但我不想这样做，我想到之前做过了一道题，求岛屿的最大面积，利用沉岛思想来做。
比如当i=0,j=0时，grid[i][j]=1,我只需要找出与grid[i][j]的上下左右相邻的柱体减去矮的那个高度乘2，四周都减了以后，将grid[i][j]置为0，这样当下一次移动到与之相邻的位置后就不会出现重复相减的情况了。
为了方便作图我使用[[1,1,1],[1,0,1],[1,1,1]]来说明
假设我们先从1号方块开始，
![image.png](https://pic.leetcode-cn.com/ab43d26cbdcc14d31166820f9d52493842055fe2c398ed17842c3b331d099370-image.png)
只需要减去1号和3号、4号的高度之间的重合部分，然后将1号柱体高度置为0
![image.png](https://pic.leetcode-cn.com/9291b9898ac4c35559d6948873ab20927786dd3c650e8f2a6163eeb8b31afaa9-image.png)
这样在计算3号和4号柱体与其他相邻的时候就不会再次减去与1号柱体相邻的面积了

对我来说挺满意的成绩了
![image.png](https://pic.leetcode-cn.com/c0b597f97bb8fe5fd4948ec6ff84a457c42a6af91f99337d7775d55fe540d91f-image.png)



### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int areaNum = 0;  //存放所有柱体的总表面积
        int repeatArea = 0;  //存放柱体之间相邻的面积
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                areaNum += CountArea(grid[i][j]);
                if (grid[i][j] != 0) {
                    repeatArea += SinkingIsland(grid, i, j);
                }
            }
        }
        return areaNum-repeatArea;
    }
    //计算柱体的表面积，当柱体高度为0时，返回0
    public int CountArea(int i) {
        if (i == 0) {
            return 0;
        }
        return 2+4*i;
    }

    public int SinkingIsland(int[][] grid, int x, int y) {
        int num = 0;
        int s=grid[x][y];
        //判断边界，避免出现越界
        if (x > 0) {
            num += (Math.min(s,grid[x-1][y]))*2;

        }
        if (x < grid.length - 1) {
            num += (Math.min(s,grid[x+1][y]))*2;

        }
        if (y > 0) {
            num += (Math.min(s,grid[x][y-1]))*2;

        }
        if (y < grid.length - 1) {
            num += (Math.min(s,grid[x][y+1]))*2;

        }
        grid[x][y]=0;  //将该位置的柱体高度置为0
        return num;
    }
}
```