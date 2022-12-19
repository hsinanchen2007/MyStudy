### 解题思路
将三维多个正方体画出来即可参透

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int result = 0;
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[i].length;j++){
                int cube = grid[i][j];
                if (cube <= 0){
                    continue;
                }
                int temp = cube*6;
                //先减去3维高度上的遮蔽面积
                temp -= (cube-1)*2;
                //减去垂直投影看到的上面的遮蔽面积，接触的面各一个，乘2
                temp -= i>0?2*Math.min(cube,grid[i-1][j]):0;
                //减去垂直投影看到的左面的遮蔽面积，接触的面各一个，乘2
                temp -= j>0?2*Math.min(cube,grid[i][j-1]):0;
                result += temp;
            }
        }
        return result;
    }
}
```