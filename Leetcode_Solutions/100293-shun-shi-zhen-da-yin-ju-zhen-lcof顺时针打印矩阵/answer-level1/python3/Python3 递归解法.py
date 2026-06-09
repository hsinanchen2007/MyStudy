![image.png](https://pic.leetcode-cn.com/c3b406b669362ce66ca60e77d39eaa6cd91bb55d3779ee0dff2ce8fcc021195e-image.png)
因为我们是一圈一圈的输出数字，我们可以定义一个函数输出外围的圈，然后把里面的部分交给递归函数来做。  

输入：圈的范围

终止条件：
1. 给的范围围不成一个圈：返回空集
2. 只剩下一行或者一列：返回这一行或一列的结果  

函数行为：
1. 把外围的圈用上图的顺序剥下来。
2. 把内部矩阵的结果加在外围的结果后面输出

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def print_clockwise(left, right, up, down):
            ls = []
            # if index is out of boundary, return empty list
            if left > right or up > down:
                return []
            for i in range(left, right):  # left -> right
                ls.append(matrix[up][i])
            for i in range(up, down):  # up -> down
                ls.append(matrix[i][right])

            # if there is only one column or one row, add up last item
            if left == right or up == down:
                return ls + [matrix[down][right]]

            for i in range(right, left, -1):  # right -> left
                ls.append(matrix[down][i])
            for i in range(down, up, -1):   # down -> up
                ls.append(matrix[i][left])

            # solve inner block recursively
            rest = print_clockwise(left + 1, right - 1, up + 1, down - 1)
            return ls + rest

        if not matrix:
            return []
        return print_clockwise(0, len(matrix[0]) - 1, 0, len(matrix) - 1)
```
