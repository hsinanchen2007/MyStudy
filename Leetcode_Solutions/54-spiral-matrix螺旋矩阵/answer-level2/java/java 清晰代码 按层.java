### 解题思路
1, 设置四个边界
2, 然后按层

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return res;
        }

        int upBound = 0;
        int bottomBound = matrix.length - 1;
        int leftBound = 0;
        int rightBound = matrix[0].length - 1;
        while (upBound <= bottomBound && leftBound <= rightBound) {
            for (int i = leftBound; i <= rightBound; i++) {
                res.add(matrix[upBound][i]);
            }
            upBound++;
            for (int i = upBound; i<= bottomBound; i++) {
                res.add(matrix[i][rightBound]);
            }
            rightBound--;
            for (int i = rightBound; upBound <= bottomBound && i >= leftBound; i--) {
                res.add(matrix[bottomBound][i]);
            }
            bottomBound--;
            for (int i = bottomBound; leftBound <= rightBound && i >= upBound; i--) {
                res.add(matrix[i][leftBound]);
            }
            leftBound++;
        }

        return res;
    }
}
```