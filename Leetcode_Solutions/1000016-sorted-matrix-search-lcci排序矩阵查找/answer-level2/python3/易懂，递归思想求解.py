### 解题思路
用传统遍历方法难免会超时，所以就想到了递归；
根据条件可知递归的模式在于找到target为止；
触发递归的条件即为当target处于相邻的两个元素之间时，将matrix截断到一定范围内继续递归。


### 代码

```python3
from typing import List


class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if target == matrix[i][j]:
                    return True
                if target < matrix[i][j]:
                    if self.searchMatrix(matrix[i + 1:], target):
                        return True
                    return False
        return False
```