### 解题思路
1.前三行，最基本的判断还是要有的，避免多余循环
2.假设横为x，竖为y，此题求解换个思路相当于求x，y
3.沿对角线遍历，那必然是x--，y++（自上而下）或y--，x++（自下而上）
4.转弯处注意边界值判断

### 代码

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null) return null;
        if (matrix.length == 0) return new int[]{};
        if (matrix.length == 1) return matrix[0];
        int size = matrix.length * matrix[0].length;
        int[] result = new int[size];
        int x = 0;
        int y = 0;
        //true代表向右上角遍历，false代表向左下角遍历
        boolean flag = true;
        for (int i = 0; i < size; i++) {
            result[i] = matrix[x][y];
            if (flag) {
                x--;
                y++;
                //边界值判断，调整顺序
                if (y > matrix[0].length - 1) {
                    y = matrix[0].length - 1;
                    x += 2;
                    flag = false;
                }
                //边界值判断，调整顺序
                if (x < 0) {
                    x = 0;
                    flag = false;
                }
            } else {
                x++;
                y--;
                //边界值判断，调整顺序
                if (x > matrix.length - 1) {
                    x = matrix.length - 1;
                    y += 2;
                    flag = true;
                }
                //边界值判断，调整顺序
                if (y < 0) {
                    y = 0;
                    flag = true;
                }
            }
        }
        return result;
    }
}
```