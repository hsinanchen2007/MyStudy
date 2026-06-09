### 解题思路
一圈一圈打印即可。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        // 最简单的思路就是按照题目要求顺时针打印即可
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        
        int left = 0, top = 0;
        int right = matrix[0].length - 1, bottom = matrix.length - 1;
        int[] res = new int[matrix.length * matrix[0].length];
        int index = 0;

        while (left <= right && top <= bottom) {
            // 从左到右打印第一排
            for (int i = left; i <= right; i++) {
                res[index++] = matrix[top][i];
            }
            // 从上到下打印最后一列 
            for (int i = top + 1; i <= bottom; i++) {
                res[index++] = matrix[i][right];
            }
            // 从右往左打印最后一排
            if (top != bottom) {
                for (int i = right - 1; i >= left; i--) {
                    res[index++] = matrix[bottom][i];
                }
            }
            // 从下至上打印第一列
            if (left != right) {
                for (int i = bottom -1; i > top; i--) {
                    res[index++] = matrix[i][left];
                }
            }
            // 打印完一周
            top++;
            left++;
            right--;
            bottom--;
        }

        return res;

    }
}
```