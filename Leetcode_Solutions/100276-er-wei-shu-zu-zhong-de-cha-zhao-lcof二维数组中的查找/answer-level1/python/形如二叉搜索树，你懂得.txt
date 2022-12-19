### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        """
        思路：从右上角开始查询（其实等价于一个二叉搜索树），如果target小于右上角的元素，那么说明
        目标值在左边的列，如果target大于右上角的元素，那么目标值肯定在下面的行
        """
        if not matrix or not matrix[0] or target < matrix[0][0]:
            return False
        i =  0  # 行
        j = len(matrix[0]) - 1 # 列
        while i < len(matrix) and j >= 0:
            if target == matrix[i][j]:
                return True
            if target < matrix[i][j]:
                j -= 1
            if target > matrix[i][j]:
                i += 1
        return False
```