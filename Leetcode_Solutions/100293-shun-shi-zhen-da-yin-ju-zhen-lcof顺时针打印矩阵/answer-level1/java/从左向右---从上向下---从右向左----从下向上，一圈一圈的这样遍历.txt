### 解题思路
此处撰写解题思路
matrix 为[]这种情况太恶心了。。。
### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
          if (matrix == null) {
            return null;
        }
        if (matrix.length == 0) {
            return new int[0];
        }

        int[] result = new int[matrix.length * matrix[0].length];
        int rightEnd = matrix[0].length - 1;
        int bottomEnd = matrix.length - 1;
        int leftEnd = 0;
        int topEnd = 0;
        int num = matrix.length * matrix[0].length;
        int count = 0;
        int cycleNum = 0;
        while (count < num) {
            // 先从左向右遍历
            if (count >= num) {
                break;
            }
            for (int i = cycleNum; i <= rightEnd; i++) {
                result[count] = matrix[topEnd][i];
                count++;
            }
            if (count >= num) {
                break;
            }
            // 从上向下遍历
            for (int i = topEnd + 1; i <= bottomEnd; i++) {
                result[count] = matrix[i][rightEnd];
                count++;
            }
            if (count >= num) {
                break;
            }
            // 从右向左遍历
            for (int i = rightEnd - 1; i >= leftEnd; i--) {
                result[count] = matrix[bottomEnd][i];
                count++;
            }
            if (count >= num) {
                break;
            }
            // 从下向上遍历
            for (int i = bottomEnd - 1; i >= topEnd + 1; i--) {
                result[count] = matrix[i][leftEnd];
                count++;
            }
            rightEnd--;
            bottomEnd--;
            leftEnd++;
            topEnd++;
            cycleNum++;
        }
        return result;
    }
}
```