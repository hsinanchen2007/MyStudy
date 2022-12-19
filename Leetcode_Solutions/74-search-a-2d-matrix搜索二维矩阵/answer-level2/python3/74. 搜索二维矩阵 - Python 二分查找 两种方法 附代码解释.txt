## 方法一：对列与行分别进行二分查找
#### 思路：
 - 第一次二分查找，找出目标值可能的所在行，判断条件：
   - 如果该行最小值大于 target，那么target不可能在较大的另一半区间内，可能在较小的另一半区间内
   - 如果该行最大值小于 target，那么target不可能在较小的另一半区间内，可能在较大的另一半区间内
   - 否则，target可能在当前行内
 - 第二次二分查找**参考了[@liweiwei1419](https://leetcode-cn.com/u/liweiwei1419)分享的[二分法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)**，该模板在解决大多数二分问题时简洁实用；
 - 找出目标值是否在所在行，判断条件：
   - 如果中间值大于目标值，那么目标值一定不在右半区间
#### 效率：
> Runtime: 80 ms, faster than 52.50% of Python3 online submissions for Search a 2D Matrix.
> Memory Usage: 16 MB, less than 5.88% of Python3 online submissions for Search a 2D Matrix.
#### 复杂度分析：
 - 时间复杂度：$O(\log m + \log n) = O(\log (mn))$
 第一次查找最多运行 $\log m$ 次，第二次查找最多运行 $\log n$ 次
 - 空间复杂度：$O(1)$
#### 代码：
```Python
from typing import List


class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        # 矩阵为空则直接返回
        if not matrix or not matrix[0]:
            return False

        R = len(matrix)
        C = len(matrix[0])

        # 如果 target不在矩阵(最小值, 最大值)范围内，直接返回
        if not (matrix[0][0] <= target <= matrix[-1][-1]):
            return False

        r, c = -1, -1

        left, right = 0, R - 1
        while left <= right:

            # 取左中位数
            mid = (left + right) >> 1

            # 如果该行最小值大于 target，那么target不可能在较大的另一半区间内，可能在较小的另一半区间内
            if matrix[mid][0] > target:
                right = mid - 1
            # 如果该行最大值小于 target，那么target不可能在较小的另一半区间内，可能在较大的另一半区间内
            elif matrix[mid][-1] < target:
                left = mid + 1
            # 否则，target可能在当前行内
            else:
                # print(f'{matrix[mid][0]} <= {target} <= {matrix[mid][-1]}')
                r = mid
                break

        left, right = 0, C- 1
        while left < right:

            # 取右中位数
            mid = (left + right) + 1 >> 1

            # 如果右中值大于target，那么target一定不在右半区间
            if matrix[r][mid] > target:
                right = mid - 1
            else:
                left = mid

        c = left

        # 对最终结果值进行判断
        return matrix[r][c] == target
```
## 方法二： 对二维数组进行降维
#### 思路：
 - 与[官方题解](https://leetcode-cn.com/problems/search-a-2d-matrix/solution/sou-suo-er-wei-ju-zhen-by-leetcode/)类似，建议参考官方题解的图例
 - 参考了[@liweiwei1419](https://leetcode-cn.com/u/liweiwei1419)分享的[二分法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)，该模板在解决大多数二分问题时可减少判断条件
 - 二分查找的判断条件：
   - 如果中间值小于目标值，那么目标值一定不在左半区间
#### 效率：
> Runtime: 72 ms, faster than 94.31% of Python3 online submissions for Search a 2D Matrix.
> Memory Usage: 15.9 MB, less than 5.88% of Python3 online submissions for Search a 2D Matrix.
#### 复杂度分析：
 - 时间复杂度：$O(\log (mn))$
 在大小为 $m*n$ 的一维数组中进行二分查找
 - 空间复杂度：$O(1)$
#### 代码：
```Python
from typing import List


class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        # 矩阵为空则直接返回
        if not matrix or not matrix[0]:
            return False

        R = len(matrix)
        C = len(matrix[0])

        # 二分查找
        left, right = 0, R * C - 1
        while left < right:

            # 取左中位数
            mid = (left + right) >> 1
            # row = idx // n ， col = idx % n
            mid_val = matrix[mid // C][mid % C]

            # 如果左中间值小于target，那么target一定不在左半区间
            if mid_val < target:
                left = mid + 1
            else:
                right = mid

        # 对最终结果值进行判断
        return matrix[left // C][left % C] == target
```