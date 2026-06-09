观察题目可的出规律：
旋转后的矩阵二维下标分别为 N - 1递减，与从零开始递增至N - 1.

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        matrix_len = len(matrix)
        line_len = len(matrix[0])
        import copy
        tmp = copy.deepcopy(matrix)
        
        for i in range(matrix_len):
            for j in range(line_len):
                k = matrix_len -1 - j
                matrix[i][j] = tmp[k][i]
        
        return matrix
```