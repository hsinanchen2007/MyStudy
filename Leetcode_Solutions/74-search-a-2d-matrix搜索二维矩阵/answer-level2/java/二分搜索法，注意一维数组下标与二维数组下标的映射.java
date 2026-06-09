### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) {
            return false;
        }
        int R = matrix.length;
        int C = matrix[0].length;
        int low = 0;
        int high = R * C - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / C;
            int c = mid - r * C;
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

}
```