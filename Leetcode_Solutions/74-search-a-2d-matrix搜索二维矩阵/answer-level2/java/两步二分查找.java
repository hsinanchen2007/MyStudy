### 解题思路
分两步求解
1 使用二分查找先确定target在矩阵中所处的行
2 使用二分查找在target所在的行中查找target
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int index = matrix.length - 1;
        if (index == -1) {
            return false;
        }
        int col = matrix[0].length-1;
        if (col == -1) {
            return false;
        }
        // 1使用二分查找先确定target所在的行
        int front = 0, later = index;
        int mid = front + (later - front)/2;
        while (front <= later) {
            if (matrix[mid][0] <= target && matrix[mid][col] >= target) {
                break;
            } else if( matrix[mid][0] > target) {
                later = mid - 1;
            } else {
                front = mid + 1;
            }
            mid = front + (later - front)/2;
        }
        if(front > later) {
            return false;
        }
        
        //2 使用二分查找在target所在的行中查找target
        int l = 0, r = col;
        while (l<=r) {
            int mid1 = l + (r - l)/2;
            if (matrix[mid][mid1] == target) {
                return true;
            } else if (matrix[mid][mid1] < target) {
                l = mid1 + 1;
            } else {
                r = mid1 - 1;
            }
        }
        return false;
    }
}
```