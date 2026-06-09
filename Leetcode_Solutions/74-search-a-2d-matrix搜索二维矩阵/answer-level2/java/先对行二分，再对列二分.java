### 解题思路
先对行二分，再对列二分

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
         if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int rowNum = matrix.length;
        int colNum = matrix[0].length;
        int pre = 0;
        int post = rowNum - 1;
        while (pre < post) {
            int mid = (pre + post) >>> 1;
            if (matrix[mid][0] > target) {
                post = mid;
            } else if (matrix[mid][0] < target) {
                pre = mid + 1;
            } else {
                return true;
            }
        }
        if (pre == 0 && matrix[0][0] > target) {
            return false;
        }
        if (matrix[pre][0] > target) {
            pre--;
        }
        int[] arr = matrix[pre];
        pre = 0;
        post = colNum - 1;
        while (pre < post) {
            int mid = (pre + post) >>> 1;
            if (arr[mid] > target) {
                post = mid;
            } else if (arr[mid] < target) {
                pre = mid + 1;
            } else {
                return true;
            }
        }
        return arr[pre] == target;
    }
}
```