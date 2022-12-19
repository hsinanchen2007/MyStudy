### 思路

##### 解法一

**暴力**

```
直接暴力遍历，遇到相同就返回 True，遍历完所有还没有遇到就返回 False。
```

**时间复杂度:** O(n*m)，n 为 matrix 矩阵的行数，m 为 matrix 矩阵的列数。
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # solution one: 暴力
        # 特判
        if matrix == []:
            return False
        
        n, m = len(matrix), len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == target:
                    return True
                elif matrix[i][j] > target:
                    break
        return False
```

##### 解法二

**左下角标志数法**

```
从左下角开始判断
如果相等，就返回；
如果大于 target，就表示该行最小值都要大于 target，所以往上移一行；
如果小于 target，就表示该列最大值都要小于 target，所以往右移一列。
```

**时间复杂度:** O(n + m)，n 为 matrix 矩阵的行数，m 为 matrix 矩阵的列数。
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # solution two: 左下角标志数法
        i, j = len(matrix) - 1, 0
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0240-Search-a-2D-Matrix-II/0240.py)