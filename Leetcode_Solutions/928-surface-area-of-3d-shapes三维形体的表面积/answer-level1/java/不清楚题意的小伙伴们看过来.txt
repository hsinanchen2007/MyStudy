### 解题思路
```
举个栗子，输入的是[[1,2],[3,4]],我们转换一下就是这个样子：
[
  [1，2]
，[3，4]
]
想象一下现在以俯视角来看上面的二维数组，数字表示的是立方体的堆叠个数，左上角的1表示只叠了1个，右上角的2表示叠了2个，它们紧挨在一起
，现在我们要算的就是这堆立方体的表面积了

```


### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {

        //计算三种重叠方式的重叠数
        //垂直重叠，行重叠，列重叠

        int chuzhi = 0;
        int hang = 0;
        int lie = 0;

        //所有立方体的总个数
        int sum = 0;

        //重叠数
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length - 1; j++) {
                int now = grid[i][j];
                int next = grid[i][j + 1];
                if (now != 0 && next != 0) hang += Math.min(now, next);//计算行重叠数

            }

        }

        //计算列重叠
        for (int i = 0; i < grid[0].length; i++) {
            for (int j = 0; j < grid.length - 1; j++) {
                int now = grid[j][i];
                int next = grid[j + 1][i];
                if (now != 0 && next != 0) lie += Math.min(now, next);//计算列重叠数
            }

        }

        //计算立方体数和垂直重叠数
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                sum += grid[i][j];
                if (grid[i][j] != 0) chuzhi += grid[i][j] - 1;
            }

        }


        return sum * 6 - (chuzhi + hang + lie) * 2;


    }
}
```