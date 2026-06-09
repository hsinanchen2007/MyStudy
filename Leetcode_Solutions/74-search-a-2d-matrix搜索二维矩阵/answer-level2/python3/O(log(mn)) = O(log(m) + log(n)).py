## 思路:

一句话解释: 二维数组转一维,用二分法

详细解释, 

二维变成一维,就是按照二维数组顺序,依次变成一维数列,所以有如果一个数在一维坐标位置是`loc`,那么它在二维坐标就是`[loc/col][loc%col]`

时间复杂度: $O(log(mn)) = O(log(m) + log(n))$

## 代码:

```python [1]
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix: return False
        row = len(matrix)
        col = len(matrix[0])
        left = 0
        right = row * col
        while left < right:
            mid = left + (right - left) // 2
            if matrix[mid // col][mid % col] < target:
                left = mid + 1
            else:
                right = mid
        #print(left,right)
        return left < row * col and matrix[left // col][left % col] == target
```



```java [1]
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int row = matrix.length;
        int col = matrix[0].length;
        int left = 0;
        int right = row * col;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / col][mid % col] < target) left = mid + 1;
            else right = mid;
        }
        return (left < row * col && matrix[left / col][left % col] == target); 
    }
}
```



