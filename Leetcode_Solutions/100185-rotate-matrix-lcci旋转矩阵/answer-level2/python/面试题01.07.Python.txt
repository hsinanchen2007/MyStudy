### 解题思路
解题思路其实也很简单，我们只看对于相差90°的四个相关元素来说，顺时针旋转90°相当于逆时针方向两两交换。

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        if N % 2:
            m = N // 2
            n = m + 1
        else:
            m = n = N // 2
        for i in range(m):
            for j in range(n):
                tmp_i, tmp_j = i, j
                for _ in range(3):
                    matrix[tmp_i][tmp_j], matrix[N - 1 - tmp_j][tmp_i] = matrix[N - 1 - tmp_j][tmp_i], matrix[tmp_i][tmp_j]
                    tmp_i, tmp_j = N - 1 - tmp_j, tmp_i
```