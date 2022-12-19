### 解题思路
题目有点费解，看了别人的题解之后才明白了题目的意思。
输入[1,2,3][5,0,9][4,5,6]，表示3行3列的网格，具体数字表示此格子上有几个方块。

每个方块有上下两个面+四周的面积。也就是格子高度*4+2，如果高度为0则表面积为0；
每当增加一个相邻的方块，则需要加上新增格子的表面积，并减去重叠部分的面积。重叠部分的面积等于重叠高度*2

所以只需要遍历一次，累加表面积即可。
遍历的时候，需要与当前方块的左边方块和上一行当前列的方块对比重叠数量。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        //一个坐标的表面积为 方块高度n*4+2 ,4是四周的面积，2是上下表面积
        //每加一个相邻的方块，都需要减去重叠的面积，重叠方块个数*2
        int result =0;
        int row = grid.length;
        //上一行的宽度（列数）
        int last_col = 0;
        //左边块的高度
        int last_height = 0;
        //遍历行
        for(int i = 0;i<row;i++){
            int col = grid[i].length;
            //遍历列
            for(int c =0; c< col; c++){
                //先与左侧方块做对比
                int height = grid[i][c];
                int current_area = 0;
                if(height >0){
                    current_area = height * 4 + 2;
                    int overlay_height = Math.min(height, last_height);
                    result += current_area;
                    if(overlay_height > 0){
                        result -= overlay_height * 2;
                    }
                    
                    //再与上方方块做对比
                    if( last_col >0 && grid[i-1][c] > 0){
                        int up_height = grid[i-1][c];
                        int up_overlay_height = Math.min(height, up_height);
                        result -= up_overlay_height * 2;
                    }
                }
                last_height = height;
            }
            last_col = col;
            last_height = 0;
        }
        return result;
    }
}
```