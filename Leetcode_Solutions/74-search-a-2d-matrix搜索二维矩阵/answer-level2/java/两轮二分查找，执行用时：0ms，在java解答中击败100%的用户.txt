### 解题思路
首先用一轮二分查找，确定有没有在某行数据里，缩小范围到单行后，再在此行中二分查找一次

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return false;
        }

        int top = 0, down = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        int center = -1, mid;

        boolean foundRow = false;

        while (top <= down) {
            center = (top + down) / 2;
            if (matrix[center][0] > target) {
                down = center - 1;
            } else if (matrix[center][right] < target) {
                top = center + 1;
            } else {
                foundRow = true;
                break;
            }
        }

        if (foundRow) {
            while (left <= right) {
                mid = (left + right) / 2;
                int x = matrix[center][mid];
                if (x > target) {
                    right = mid - 1;
                } else if (x < target) {
                    left = mid + 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
}
```