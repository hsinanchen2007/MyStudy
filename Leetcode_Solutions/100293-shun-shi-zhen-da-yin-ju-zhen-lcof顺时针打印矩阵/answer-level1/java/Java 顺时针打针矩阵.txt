### 解题思路
更新题解记录：
循环条件即边界控制条件
方向改变的时候注意变量变更，代码中有一行注释的和上面那行是等价的。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new int[]{};
        }

        int rows = matrix.length, cols = matrix[0].length;
        int rowTop = 0, rowBottom = rows - 1;
        int colLeft = 0, colRight = cols - 1;
        int point = 0, i = 0, j = 0;

        int[] result = new int[rows * cols];
        int index = 0;
        // 循环结束条件要记住！！！
        while (rowTop <= rowBottom && colLeft <= colRight) {
            result[index++] = matrix[i][j];
            switch(point) {
                case 0:
                    if (j == colRight) {
                        point = 1;
                        i = ++rowTop; // 与下面注释的这行是等价的
                        // rowTop = ++i;                        
                    } else {
                        j++;
                    }
                    continue;
                case 1:
                    if (i == rowBottom) {
                        point = 2;
                        j = --colRight;
                        // colRight = --j;
                    } else {
                        i++;
                    }
                    continue;
                case 2:
                    if (j == colLeft) {
                        point = 3;
                        i = --rowBottom;
                        // rowBottom = --i;
                    } else {
                        j--;
                    }
                    continue;
                case 3:
                    if (i == rowTop) {
                        point = 0;
                        j = ++colLeft;
                        // colLeft = ++j;
                    } else {
                        i--;
                    }
            }
        }
        return result;
    }
}
```