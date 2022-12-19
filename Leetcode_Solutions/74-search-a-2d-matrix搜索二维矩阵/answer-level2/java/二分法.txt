### 解题思路
把二维的合在一起，变成一维的数组，然后用二分查找。

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length, n = matrix[0].length;
        int start = 0, end = m * n - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int midNum = matrix[mid / n][mid % n];
            if(midNum < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if(matrix[start / n][start % n] == target) {
            return true;
        }
        if(matrix[end / n][end % n] == target) {
            return true;
        }
        
        return false;
    }
}
```