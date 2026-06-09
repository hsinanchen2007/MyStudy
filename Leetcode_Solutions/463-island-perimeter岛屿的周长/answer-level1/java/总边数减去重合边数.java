### 解题思路
    1. 我们知道单独一块的周长是4，那么理论上如果能找到n块，总周长是4n；
    2. 然而，如果两块是邻近关系，那很明显，周长为2 x 4 - 1 x 2 = 6；
    3. 那么放到代码中体现，就是扫grid，如果是1，则判断其四周是否存在land；
    4. 判断是否存在land的方法，要定义两个分别能表示左右上下相对当前位置的四个邻边x和y坐标：
       p = (2,3), 那么四个邻边位置（按左右上下）是：(2,3), (2,4), (1,3), (3,3);
    5. 最后不要忘了防止下标越界；

![捕获.PNG](https://pic.leetcode-cn.com/16c7edc56071b1f251e2266262f3ee1599ca33bde4a02bb2dbebebd7880164b8-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
       // four adjacents position for current land
       int[] rowSide = new int[]{0, 0, -1, 1};
       int[] colSide = new int[]{-1, 1, 0, 0};
       int perimeter = 0, count = 0;
       for (int i = 0; i < grid.length; i++) {
           for (int j = 0; j < grid[i].length; j++) {
               if (grid[i][j] == 1) {   // is land
                    perimeter += 4;
                    for (int k = 0; k < 4; k++) {
                        int x_move = colSide[k];
                        int y_move = rowSide[k];
                        int side_x = i - x_move;
                        int side_y = j - y_move;
                        if ((side_x >= 0 && side_x < grid.length) && (side_y >= 0 && side_y <                             grid[i].length)) {
                            if (grid[i - x_move][j - y_move] == 1) {
                                perimeter -= 1;
                                // System.out.println("[" + i + "," + j + "]");
                            }
                        }
                    }
               }
           }
       }
       return perimeter;
    }
    
}
```