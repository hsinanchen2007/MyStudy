### 解题思路
模拟过程

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {

        if (matrix.length == 0) {
            return new int[0];
        }

        int width = matrix[0].length;
        int height = matrix.length;

        int[] rs = new int[width * height];
        int p = 0;

        int t = 0,r = 0,b = 0,l = 0,direction = 0,x = 0,y = 0;
        while (p < rs.length) {
            rs[p] = matrix[y][x];
            if (direction == 0) {//to right
               if (x < width - r -1) {
                   x ++;
               } else {
                   y ++;
                   direction = 1;
                   t ++;
               } 
            } else if (direction == 1) {//to bottom
                if (y < height - b-1) {
                    y ++;
                } else {
                    x --;
                    direction = 2;
                    r ++;
                }
            } else if (direction == 2) {//to left
                if (x > l ) {
                    x --;
                } else {
                    y--;
                    direction = 3;
                    b ++;
                }
            } else {//to top
                if (y > t ) {
                    y --;
                } else {
                    x++;
                    direction = 0;
                    l ++;
                }
            }
            p++;
        }
        return rs;
    }
}
```