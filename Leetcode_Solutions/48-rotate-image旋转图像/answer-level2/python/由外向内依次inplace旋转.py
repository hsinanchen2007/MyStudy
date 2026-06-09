### 解题思路
最外层循环是由最外层向最里层依次旋转，旋转n//2次
第二层循环是每层旋转保留顶层元素，依次left->top，bottom -> left，right -> bottom，top -> right赋值
注意每一层旋转时，每一边的行数与列数在赋值时怎么样去表示，也就是行列的的变化情况，是什么在不变，什么在减小，增大

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for layer in range(n//2):
            first = layer#在接下来依次赋值时可以代表第first行（列）
            last = n - 1 - layer#在接下来依次赋值时可以代表第last行（列）
            for i in range(first, last):
                offset = i - first#旋转了几个元素
                top = matrix[first][i]  # save top
                
                ## left（行减小，列不变）->top（行不变，列增大）
                matrix[first][i] = matrix[last-offset][first]
                
                ##bottom（行不变，列减小） -> left
                matrix[last-offset][first] = matrix[last][last - offset];

                # right（行增大，列不变） -> bottom
                matrix[last][last - offset] = matrix[i][last];

                # top -> right
                matrix[i][last] = top;  # right <- saved top    
```