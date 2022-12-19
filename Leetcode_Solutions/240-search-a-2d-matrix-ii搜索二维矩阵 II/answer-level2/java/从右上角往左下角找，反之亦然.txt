### 解题思路
从右上角往左下角找，反之亦然。
我在面试头条的时候遇到过原题。

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length, n = matrix[0].length;
        int i = 0, j = n - 1;
        int cnt = 0;
        while(i < m && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        
        return false;
    }
}
```