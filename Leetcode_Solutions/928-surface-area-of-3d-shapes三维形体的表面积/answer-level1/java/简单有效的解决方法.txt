### 解题思路
遍历网状格每个点的物块表面积（可能有几个物块摞在一起放在这个点）
①分析该物块前后左右上下的情况 
②例如:如果该点前面没有，那么该点物体前面的表面积，就是该点摞了几个物块的数量；
      如果该点前面有物块，那么该点前面的表面积分两种情况：
            1、前面摞的物块没该点高，则该点前面的表面积为两者之差；
            2、前面摆的比该点摆的高，则该点前面的表面积为0；                                                 3、同理算其他。
③上下表面积：只要该点有物块，那么上下的表面积为2. 没有则为0

可写成以下代码：
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {

        int len = grid.length;  //长度  N*N网格长宽一样
        int num = 0;//结果

        //遍历网状格每个地点放的物块表面积
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){

                //当前物块 前面 是否有物块 
                num += i + 1 >= len ? grid[i][j] : Math.max((grid[i][j] - grid[i + 1][j]),0);

                //后
                num += i - 1 < 0 ? grid[i][j] : Math.max((grid[i][j] - grid[i - 1][j]),0);

                //左
                num += j - 1 < 0 ? grid[i][j] : Math.max((grid[i][j] - grid[i][j - 1]),0);
        
                //右
                num +=  j + 1  >= len ? grid[i][j] : Math.max((grid[i][j] - grid[i][j + 1]),0);    

                //上和下 只要有方块 上下只有2个表面积
                num += grid[i][j] == 0 ? 0 : 2;
            }
        }

        return num;
    }
}
```