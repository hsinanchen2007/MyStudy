
#### 说明：
 - 思路与 [Spiral Matrix II （模拟法，设定边界，代码简短清晰）](https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/) 相似
 - 整体思路上，另一种方法会更加清晰
#### 思路：
 - 生成一个``n * n``的矩阵
 - 随后根据每行每列所需的填充行为，从最外至内依序环绕填充数值
   - 假设层数为n，那么第k个数需要填写的位置为
     - 第一行　：``顺序`` ``[0, n - 1)``
     - 最后一列：``顺序`` ``[n - 1, 2 * (n - 1))``
     - 最后一行：``逆序`` ``[2 * (n - 1), 3 * (n - 1))``
     - 第一列　：``逆序`` ``[3 * (n - 1), 4 * (n - 1))``
    - 填充完外层后，在用相同方法填充内层，直至所有层数都填充完毕
    - 注意层数为奇数时，``range(n, 0, -2)``无法覆盖到最内层（1x1），因此需要填充一次最内层数
#### 效率：
 > Runtime: 36 ms, faster than 81.98% of Python3 online submissions for Spiral Matrix II.
 > Memory Usage: 13.8 MB, less than 9.09% of Python3 online submissions for Spiral Matrix II.
#### 复杂度分析：
 - 时间复杂度：$O(n^2)$
   遍历一次矩阵，矩阵大小为 $n*n$
 - 空间复杂度：$O(n^2)$
   需要创建一个大小为 $n*n$ 的矩阵
#### 代码：
```Python
from typing import List


class Solution:

    def generateMatrix(self, n: int) -> List[List[int]]:

        # 预创建矩阵
        matrix = [[0] * n for _ in range(n)]

        # 当前数值
        i = 1

        # 从最外层向最内层，逐层构造
        # 内层比外层少2个元素
        for j in range(n, 0, -2):

            # 当前层数的起始x, y
            start_x, start_y = (n - j) // 2, (n - j) // 2

            # 本次遍历起始的x, y
            x, y = 0, 0

            # 开始遍历，每层至多遍历4 * (j - 1)次
            for k in range(4 * (j - 1)):

                # 设置矩阵对应位置的值
                # 当前层的起始坐标加上遍历过程中变化的坐标，即是整个矩阵中对应的位置
                matrix[start_y + y][start_x + x] = i
                # 数值加一
                i += 1

                # 顺序填充，第一行
                if 0 <= k < j - 1:
                    # 顺序增一
                    x += 1
                # 顺序谭崇，最后一列
                elif j - 1 <= k < 2 * (j - 1):
                    # 顺序增一
                    y += 1
                # 逆序填充，最后一行
                elif 2 * (j - 1) <= k < 3 * (j - 1):
                    # 逆序增一
                    x -= 1
                # 逆序填充，第一列
                elif 3 * (j - 1) <= k < 4 * (j - 1):
                    # 逆序增一
                    y -= 1

        # 如果n为奇数，则最中间的的数仍未调整
        if n % 2:
            matrix[n // 2][n // 2] = i

        return matrix
```