```java
class Solution {
    // 二分查找，我们可以将二维数组转成一维数组来左；
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int R = matrix.length;
        int C = matrix[0].length;
        int N = R * C; // 0 ~ N - 1 个元素;
        int start = 0;
        int end = N - 1;
        while (start < end) {
            int mid = (start + end) >>> 1;
            if (matrix[mid / C][mid % C] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return matrix[start / C][start % C] == target;
    }
}
```
