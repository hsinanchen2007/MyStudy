### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int lastRow = matrix.length - 1;
        int lastColumn = matrix[0].length - 1;

        return searchMatrix(matrix, 0, 0, lastRow, lastColumn, target);
    }

    private boolean searchMatrix(int[][] matrix, int startRow, int startColumn,
    int lastRow, int lastColumn, int target) {
        if (startRow > lastRow || startColumn > lastColumn) {
            return false;
        }
        if (startRow == lastRow && startColumn == lastColumn) {
            return target == matrix[startRow][startColumn];
        }
        int midRow = (startRow + lastRow) / 2;
        int midColumn = (startColumn + lastColumn) / 2;
        int midVal = matrix[midRow][midColumn];
        if (target == midVal) {
            return true;
        } else {
            boolean rightUpper = searchMatrix(matrix, startRow, midColumn + 1,
            midRow, lastColumn, target);
            boolean leftDown = searchMatrix(matrix, midRow + 1, startColumn,
            lastRow, midColumn, target);
            if (rightUpper || leftDown) {
                return true;
            }
            if (midVal > target) {
                return searchMatrix(matrix, startRow, startColumn, midRow, midColumn, target);
            } else {
                return searchMatrix(matrix, midRow + 1, midColumn + 1, lastRow,
                lastColumn, target);
            }
        } 
    } 

    
}
```