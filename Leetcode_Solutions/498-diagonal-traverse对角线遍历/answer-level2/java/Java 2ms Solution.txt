思路：从起始位置开始，左下往右上遍历过程和右上往左下遍历过程来回切换，直到遍历完最后一个元素
同时，每次向上或向下遍历过后，都要记录下一次遍历的起始位置
详见代码：
```
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
            if (matrix == null || matrix.length == 0) {
                return new int[0];
            }
            int m = matrix.length;
            int n = matrix[0].length;
            int[] result = new int[m * n];
            // i,j 记录遍历的起始位置
            int i = 0, j = 0, k = 0;
            boolean isUp = true;
            while (i < m && j < n) {
                if (isUp) {
                    int x, y;
                    // 从左下往右上遍历
                    for (x = i, y = j; x >= 0 && y < n; x--, y++) {
                        result[k++] = matrix[x][y];
                    }
                    // 恢复位置
                    x++;
                    y--;
                    // 计算下一次遍历的起始位置
                    if (y < n - 1) {
                        j = y + 1;
                        i = x;
                    } else {
                        j = y;
                        i = x + 1;
                    }
                    isUp = false;
                } else {
                    int x, y;
                    // 从右上往左下遍历
                    for (x = i, y = j; x < m && y >= 0; x++, y--) {
                        result[k++] = matrix[x][y];
                    }
                    // 恢复位置
                    x--;
                    y++;
                    // 计算下一次遍历的起始位置
                    if (x < m - 1) {
                        i = x + 1;
                        j = y;
                    } else {
                        i = x;
                        j = y + 1;
                    }
                    isUp = true;
                }
            }
            return result;
        
    }
}
```
