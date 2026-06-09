相同问题：[240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)。

### 方法一：减而治之

![4-1.jpg](https://pic.leetcode-cn.com/39135ce30976f053a8f3b4db7b3756b1f77fd8be91341bbdd1ffc7d2403d137f-4-1.jpg)

**参考代码 1**：

说明：Java 代码展示了从左下角开始查找，Python 代码展示了从右上角开始查找。

```Java []
public class Solution {

    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int rows = matrix.length;
        if (rows == 0) {
            return false;
        }

        int cols = matrix[0].length;
        if (cols == 0) {
            return false;
        }

        // 从左下角开始查找
        int x = rows - 1;
        int y = 0;

        while (x >= 0) {

            while (y < cols && matrix[x][y] < target) {
                y++;
            }

            if (y < cols && matrix[x][y] == target) {
                return true;
            }

            x--;
        }
        return false;
    }
}
```
```Python []
from typing import List


class Solution:

    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        if rows == 0:
            return False

        cols = len(matrix[0])
        if cols == 0:
            return False

        # 从右上角开始查找
        x = 0
        y = cols - 1
        while x < rows and y >= 0:
            if target == matrix[x][y]:
                return True
            elif target < matrix[x][y]:
                y -= 1
            else:
                x += 1
        return False
```


### 方法二：二分查找（不推荐）

一个一个比较慢，可以利用二维矩阵的有序性，使用二分查找的办法。以从右上角开始查找为例，二分法查找的思路是：

1、从右到左，找第 1 个小于或者等于 `target` 的数；
2、从上到下，找第 1 个大于或者等于 `target` 的数。

这样写出来的代码相对是晦涩难懂，不易维护的，只是作为练习，在工程中不建议这样写。


**参考代码 2**：

```Python []
from typing import List


class Solution:

    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        if rows == 0:
            return False
        cols = len(matrix[0])
        if cols == 0:
            return False

        # 从右上角开始查找
        x = 0
        y = cols - 1

        while x < rows and y >= 0:

            # print('x', x, 'y', y, array[x][0])
            # 1、从右到左，找第 1 个小于或者等于 target 的数
            if y == 0 and matrix[x][0] > target:
                return False
            left = 0
            right = y
            while left < right:
                mid = left + (right - left + 1) // 2
                if matrix[x][mid] <= target:
                    left = mid
                else:
                    # assert array[x][mid] > target
                    right = mid - 1

            y = left
            # 2、从上到下，找第 1 个大于或者等于 target 的数
            if x == rows - 1 and matrix[rows - 1][y] < target:
                return False

            left = x
            right = rows - 1
            while left < right:
                mid = left + (right - left) // 2
                if matrix[mid][y] >= target:
                    right = mid
                else:
                    # assert array[mid][y] < target
                    left = mid + 1
            x = left

            if matrix[x][y] == target:
                return True

        return False
```