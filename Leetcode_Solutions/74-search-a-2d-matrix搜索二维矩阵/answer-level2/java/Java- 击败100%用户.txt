### 解题思路
* 从左上角元素开始,可以看到左边的元素都是比它小的,下边的元素都是比它大的.
* 所有根据这个规律可以从左上角开始遍历,当 num > target时,则从元素行向左查找,当num < target时,则移到下一行
>   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]

### 代码

```java
   public static boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int row = 0;
        int col = matrix[0].length - 1;
        while (row < matrix.length && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
```

由于每一行元素都是有序的,所有当锁定了元素行时,可以利用二分查找加快搜索速度.

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
         if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int row = 0;
        int col = matrix[0].length - 1;
        while (row < matrix.length) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                //因为每一个都是有序的,所以对每行可以使用二分查找进一步加快搜索速度
                return Arrays.binarySearch(matrix[row], target) >= 0;
            } else {
                row++;
            }
        }
        return false;
    }
}
```