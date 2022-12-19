之前忘了那个公司笔试见过这道题了，开始一直想着求各个面的投影，没有考虑到中间有凹陷的情况。特来温习一下。

主要思路，一个正方体六个面，如果两个正方体有接触，则会减少两个面。所以表面积 S = 正方体总个数 N * 6 - 所有正方体接触面的个数 M * 2 ；

依次判断每个位置跟相邻位置的接触面个数，这种方法存在重复。例如A与B接触，计算一次，B与A接触又计算了一次。 所以从（0，0）开始，每个位置只和右边、下边比较，这样避免重复。需要考虑一些边界情况，有问题的可以下面提出～～


```
class Solution {
    public int surfaceArea(int[][] grid) {
        int sum = 0 ;   //计算正方体总个数

        int cnt = 0 ;   //计算所有接触面的个数
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                sum += grid[i][j];    
                cnt += grid[i][j]>=1?grid[i][j]-1:0;   
//这里有个坑，开始用的 cnt +=grid[i][j] - 1 ,如果这个位置没有放正方体，就等于加了个负数，所以加个判断。
                if(i==grid.length-1&&j<grid[0].length-1)    //最下面一列，只和右边比较
                {
                    cnt += grid[i][j]>grid[i][j+1] ? grid[i][j+1]:grid[i][j];
                }
                else if(j==grid[0].length-1 && i<grid[0].length-1)  //    最右边一列，只和下边比较
                {
                    cnt += grid[i][j]>grid[i+1][j] ? grid[i+1][j]:grid[i][j];
                }
                else if(i!=grid.length-1 && j!=grid[0].length)    //其他列和右边、下边比较，最后一个位置（N-1,N-1）不需要比较了。
                {
                    cnt += grid[i][j]>grid[i][j+1] ? grid[i][j+1]:grid[i][j];
                    cnt += grid[i][j]>grid[i+1][j] ? grid[i+1][j]:grid[i][j];
                }
            }
        }
        return sum*6 - cnt*2;
    }
}
```




