### 思路

**暴力**

##### 解法一

```
找出每一行的最小值，再判断是否是当前列的最大值。
```

**时间复杂度:** O(m*n)，m 是 matrix 的行数，n 是 matrix 的列数。

##### Python3代码

```python
from typing import List

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        # solution one
        m, n = len(matrix), len(matrix[0])
        flag = 0
        res = []
        for i in range(m):
            min_ = max_ = matrix[i][0]
            for j in range(n):
                if matrix[i][j] < min_:
                    flag = j
                    min_ = matrix[i][j]
            max_ = min_
            for x in range(m):
                if matrix[x][flag] > max_:
                    break
                elif x == m - 1:
                    res.append(max_)
        return res
```

##### 解法二

```
分别找出每一行的最小值和每一列的最大值，再判断是否相等。
```

**时间复杂度:** O(max(m, n))，m 是 matrix 的行数，n 是 matrix 的列数。

##### Python3代码

```python
from typing import List

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        # solution two
        min_ = {min(rows) for rows in matrix}
        max_ = {max(columns) for columns in zip(*matrix)}  # zip(*) 对矩阵进行转置，即找出每一列中的最大值
        return list(min_ & max_)
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1380-Lucky-Numbers-in-a-Matrix/1380.py)