### 解题思路
简单外衣下比较容易忽略的东西

### 代码

```python
class Solution(object):
    # 左下角
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # 这里如果matrix是空，则i会变成-1，进不去循环直接返回的是False
        i, j = len(matrix)-1, 0
        while i >=0 and j < len(matrix[0]):
            if matrix[i][j] == target: return True
            elif matrix[i][j] > target: i -= 1
            else: j += 1
        return False
    # 右上角,细节是魔鬼啊！！！！！！！
    def findNumberIn2DArray2(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # 而这里如果不判断matrix是否为空，则有可能找列索引时越界
        # 这里：len(matrix[0])-1 产生这样的错
        # IndexError: list index out of range
        if matrix == []:
            return False
        i, j = 0, len(matrix[0])-1
        while j >= 0 and i < len(matrix):
            if matrix[i][j] == target: return True
            elif matrix[i][j] > target: j -= 1
            else: i += 1
        return False
```