### 解题思路
这道题首先要求的肯定是元素 -> 旋转后元素的映射关系：(i, j) -> (j, n - i - 1)
其次是按照什么顺序进行旋转，其实这个顺序是无所谓的，只要能够保证不遗漏元素**且不重复**即可。

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n // 2):
            for j in range(i, n - i - 1): # 注意这里的-1
                x, y = i, j
                temp = matrix[i][j]
                for k in range(3):
                    matrix[x][y] = matrix[n - y - 1][x]
                    x_ = x
                    y_ = y
                    x = n - y_ - 1
                    y = x_
                matrix[x][y] = temp
```