### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.6 MB, 在所有 Java 提交中击败了94.70%的用户

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        if(matrix.length == 0 || matrix[0].length == 0) return false;

        int row_length = matrix[0].length, cloumn_length = matrix.length;

        int low = 0, high = row_length * cloumn_length-1, mid = 0;

        while(low <= high){

            mid = low + (high - low) / 2;

            int i = mid / row_length, j = mid % row_length;

            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target)
                high = mid - 1;
            else
                low = mid + 1; 
        }

        return false;
    }
}
```