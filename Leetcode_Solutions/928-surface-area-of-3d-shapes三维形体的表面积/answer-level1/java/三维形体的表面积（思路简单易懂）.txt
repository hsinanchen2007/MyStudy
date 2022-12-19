时间复杂度O（N^2）,空间复杂度O（1）

设置两个参数：
1、total：代表一共有多少个小立方体
2、merge：代表这些小立方体之间有多少个重叠的面
    主要包含三种重叠：上下重叠，左右重叠，前后重叠

遍历二维数组
    若当前位置的正方体数目大于1，说明存在上下重叠，重叠的面为（正方体数目-1）*2
    若当前位置的右边没有越界，则说明可能存在左右重叠。重叠的面为（当前位置正方体数目和右边正方体数目的最小值）*2
    若当前位置的下边没有越界，则说明可能存在前后重叠。重叠的面为（当前位置正方体数目和下边正方体数目的最小值）*2

最后，表面积为
area = total*6 - merge
```
public int surfaceArea(int[][] grid) {
        if (grid == null || grid.length == 0){
            return 0;
        }
        int merge = 0;
        int total = 0;
        for (int i = 0 ; i < grid.length ; i++){
            for (int j = 0 ; j < grid[0].length ; j++){
                total += grid[i][j];
                if (grid[i][j] > 1){
                    merge+= grid[i][j] - 1;
                }
                //和右边比较
                if (j < grid[0].length-1){
                    merge += Math.min(grid[i][j], grid[i][j+1]);
                }
                //和下边比较
                if (i < grid.length -1){
                    merge += Math.min(grid[i][j], grid[i+1][j]);
                }
            }
        }
        return total*6 - merge*2;
    }
```
