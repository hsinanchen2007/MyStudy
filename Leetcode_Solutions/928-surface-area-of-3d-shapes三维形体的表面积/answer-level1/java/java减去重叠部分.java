### 解题思路
grid[i][j]=value;
每一个立方体的面积是6*value-2*(value-1)化简等于4*value+2,
把grid[i][j]看成整体出现重叠面只能是上下左右四个方向即grid[i-1][j],grid[i+1][j],grid[i][j-1],grid[i][j+1]
其中i-1>=0;i+1<grid.length,j-1>=0;j+1<grid[0].length 这是四个边界情况.
但是我们可以直接判断上和左,省略掉下与右
例如如果grid[i-1][j]>0说明有重叠部分,重叠的面积Math.min(grid[i][j], grid[i-1][j]),这个重叠面积相是在grid[i][j]的上方,但也相当于在grid[i-1][j]的下方,所以重叠面积**Math.min(grid[i][j], grid[i-1][j])*2**上下面都计算了,所以只需要计算grid[i][j]上方省略下方,即可,同理只计算左方,省略右方
当然也可以不省略,只是不需要乘以2,变成**Math.min(grid[i][j], grid[i-1][j])**
### 代码

```java
import java.util.*;
class Solution {
    //第一种方法
    public  int surfaceArea(int[][] grid) {
        //定义一个队列,key是i(行),value是j(列)
        LinkedList<Map.Entry<Integer, Integer>> queue = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                //将grid[i][j]大于0的放到队列中用于计算面积
                if (grid[i][j] > 0) {
                    Map.Entry<Integer, Integer> map =
                            new AbstractMap.SimpleImmutableEntry<>(i, j);
                    queue.add(map);
                }
            }
        }
        //行
        int row = grid.length;
        //列
        int column = grid[0].length;
        //面积
        int result = 0;
        while (!queue.isEmpty()) {
            Map.Entry<Integer, Integer> map = queue.poll();
            //获取对应索引位置
            int x = map.getKey(), y = map.getValue();
            //确定值
            int value = grid[x][y];
            //计算前柱状体的面积
            result = result + 4*value+2;
            //上
            if (x - 1 >= 0 && grid[x - 1][y] > 0) {
                int up = grid[x - 1][y];
                int min = Math.min(value, up);
                result = result - min*2;
            }
            //左
            if (y - 1 >= 0 && grid[x][y - 1] > 0) {
                int left = grid[x][y - 1];
                int min = Math.min(value, left);
                result = result - min*2;
            }
        }
        return result;
    }
}
```
### 解题思路
其实不需要借助队列,也可以完成,直接在循环中进行判断
```java
class Solution {
     public int surfaceArea(int[][] grid){
         //记录面积
        int result=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                //判断grid[i][j]>0
                if(grid[i][j]>0){
                    int value=grid[i][j];
                    //计算面积
                    result=result + 4*value+2;
                    //上
                    if(i - 1 >= 0 && grid[i - 1][j] > 0){
                        int up = grid[i - 1][j];
                        int min = Math.min(value, up);
                        result = result - min*2;
                    }
                    //左
                    if(j - 1 >= 0 && grid[i][j - 1]>0){
                        int left = grid[i][j - 1];
                        int min = Math.min(value, left);
                        result = result - min*2;
                    }
                }
            }
        }
        return result;
    }
}
```