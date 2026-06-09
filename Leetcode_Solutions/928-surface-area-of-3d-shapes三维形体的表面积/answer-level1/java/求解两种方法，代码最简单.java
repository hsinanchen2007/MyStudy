### 解题思路
此处撰写解题思路
方法一：每次加值的立方体面积，然后考虑四周情况，减去连接的面（时间为6ms）
方法二：通过比较左右（上下）两个值，考虑两个长方体摆放的位置求出夹在两长方体中间的面积，以此类推，按列按行展开求左右上下（水平中）面,计算不是零的值求上下两面（空间中），时间复杂度为O(n^2)（时间3ms）
### 代码

```java


class Solution {
   //方法一
    public static int surfaceArea(int[][] grid){
      int area = 0,size = grid.length,temp;
      for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(grid[i][j] == 0) continue;
            temp = grid[i][j];
            area += (grid[i][j]*4)+2;
            if(i - 1 >= 0 )
              area -=Math.min(temp,grid[i-1][j])*2;
            if(j - 1 >= 0 )
              area -= Math.min(temp,grid[i][j-1])*2;
        }

      }
      return area;
   }
   方法二：
    public int surfaceArea(int[][] grid) {
       int area = 0,size = grid.length,num = 0,temp1,temp2;
      for(int i = 0;i < size;i++){
        temp1 = grid[i][0];
        temp2 = grid[0][i];
        area += temp1+temp2;
        for(int j = 0;j < size ;j++){
           if(grid[i][j] != 0) num++;
           area += Math.abs(temp1 - grid[i][j]) + Math.abs(temp2 - grid[j][i]);
           temp1 = grid[i][j];
           temp2 = grid[j][i];
        }
        area +=grid[i][size - 1]+grid[size - 1][i];
      }
      area += num*2;
      return area;
    }
}
```