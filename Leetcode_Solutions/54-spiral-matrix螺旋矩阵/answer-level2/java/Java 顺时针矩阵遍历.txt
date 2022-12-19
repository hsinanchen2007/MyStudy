### 解题思路
顺时针遍历矩阵
重点是方向的控制以及每一个方向的边界判断！！！

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new ArrayList<>();
        }

        int rows = matrix.length;
        int cols = matrix[0].length;
        int i = 0, j = 0, postion = 0;
        int rowTop = 0, rowBot = rows - 1, colLeft = 0, colRight = cols - 1;
        List<Integer> result = new ArrayList<>();
        while (i >= rowTop && i <= rowBot && j >= colLeft && j <= colRight) {
            result.add(matrix[i][j]);
            switch (postion) {
                case 0 : // 向右➡
                if (j == colRight) {
                    postion = 1;
                    i = ++rowTop;
                } else {
                    j++;
                }
                break;
                case 1: // 向下️⬇️
                if (i == rowBot) {
                    postion = 2;
                    j = --colRight;
                } else {
                    i++;
                }
                break;
                case 2: // 向左⬅️
                if (j == colLeft) {
                    postion = 3;
                    i = --rowBot;
                } else {
                    j--;
                }
                break;
                case 3: // 向上⬆️
                if (i == rowTop) {
                    postion = 0;
                    j = ++colLeft;
                } else {
                    i--;
                }
            }
        }
        return result;
    }
}
```