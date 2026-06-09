### 解题思路
1. 使用二分搜索，返回恰好小于或等于target的数字下标。
2. 先对列进行二分，再对行进行二分。

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // corner case
        if (matrix.length == 0 || matrix[0].length == 0|| 
        target < matrix[0][0] || 
        target > matrix[matrix.length - 1][matrix[0].length - 1]) return false;
        
        // main
        int[] row = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) row[i] = matrix[i][0];
        int rowIdx = binarySearch(row, target, 0, matrix.length);
        int colIdx = binarySearch(matrix[rowIdx], target, 0, matrix[0].length);

        return matrix[rowIdx][colIdx] == target;

        
    }

    public int binarySearch(int[] nums, int target, int left, int right){
        int idx = (left + right) / 2;
        if (nums[idx] <= target){
            if (nums[idx] == target || idx >= nums.length - 1|| nums[idx + 1] >target) return idx;
        }

        if (nums[idx] > target) return binarySearch(nums, target, left, idx);

        return binarySearch(nums, target, idx + 1, right);
    }
}
```