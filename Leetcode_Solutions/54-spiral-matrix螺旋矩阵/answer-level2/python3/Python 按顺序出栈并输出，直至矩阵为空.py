
## 说明：
 - 按顺序出栈并输出，直至矩阵为空
   1. 移动至矩阵第一行最右端，移动时输出当前值至结果列表
   2. 移动到最底部，并将每行最右端值输出至结果列表
   3. 移动至矩阵最后一行最左端，移动时输出当前值至结果列表
   4. 移动到最顶部，并将每行最左端值输出至结果列表
   5. 重复以上步骤，直至矩阵为空（所有值都出栈）
## 效率：
 - ![image.png](https://pic.leetcode-cn.com/9a12790a78ece19bd9a0709af71db09c94b3edb50aad440c7e8828ad28950b07-image.png)

## 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
## 代码：
```Python
from typing import List


class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        result = []

        def move_to_rightmost():
            """移动至矩阵第一行最右端，移动时输出当前值至结果列表"""

            # 矩阵为空，直接返回
            if not matrix:
                return

            # 输出矩阵第一行最左端（栈尾）值出栈至结果列表，直至栈为空
            while matrix[0]:
                result.append(matrix[0].pop(0))
            # 从矩阵中移除首行空栈
            matrix.pop(0)

        def move_to_bottom():
            """移动到最底部，并将每行最右端值输出至结果列表"""

            # 矩阵为空，直接返回
            if not matrix:
                return

            # 顺序输出矩阵每行的最右端值至结果列表
            for row in matrix:
                if not row:
                    continue
                # 输出栈顶（最右端）值至结果列表
                result.append(row.pop())

        def move_to_leftmost():
            """移动至矩阵最后一行最左端，移动时输出当前值至结果列表"""

            # 矩阵为空，直接返回
            if not matrix:
                return

            # 输出矩阵最后一行最右端（栈顶）值出栈至结果列表，直至栈为空
            while matrix[-1]:
                result.append(matrix[-1].pop())
            # 从矩阵中移除尾行空栈
            matrix.pop(-1)

        def move_to_top():
            """移动到最顶部，并将每行最左端值输出至结果列表"""

            # 矩阵为空，直接返回
            if not matrix:
                return

            # 逆序输出矩阵每行的最左端值至结果列表
            for row in matrix[::-1]:
                if not row:
                    continue
                # 输出栈尾（最左端）值至结果列表
                result.append(row.pop(0))

        # 按题设要求顺序执行，直至矩阵为空（所有值都出栈）
        while matrix:
            move_to_rightmost()
            # print('r', result, matrix)
            move_to_bottom()
            # print('b', result, matrix)
            move_to_leftmost()
            # print('l', result, matrix)
            move_to_top()
            # print('t', result, matrix)

        return result
```