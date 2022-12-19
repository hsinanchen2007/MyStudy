### 解题思路
此处撰写解题思路

### 代码

```java
/**注意到输入的 m x n 矩阵可以视为长度为 m x n的有序数组。
这是一个标准二分查找算法 :
        初始化左右序号
        left = 0 和 right = m x n - 1。
        While left < right :
        选取虚数组最中间的序号作为中间序号: mid = (left + right) >>> 1。
        该序号对应于原矩阵中的 row = mid / n行, col = mid % n 列, 由此可以拿到中间元素element。该元素将虚数组分为两部分。
        比较 element 与 target 以确定在哪一部分进行进一步查找。

*/
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int left = 0;
        int right = m*n-1;

        while (left < right) {
            int mid = (left + right) >>> 1;
            int element = matrix[mid/n][mid%n];

            if (element < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (matrix[left/n][left%n] == target) {
            return true;
        }
        return false;
    }
}
```