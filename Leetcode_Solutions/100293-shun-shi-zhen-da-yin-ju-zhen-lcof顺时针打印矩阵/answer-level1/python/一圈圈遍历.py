### 解题思路
注意每次的遍历减2，然后写好第一遍历

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []:
            return []
        m = len(matrix)
        n = len(matrix[0])
        i = 0
        j = -1
        res = []
        k = 0
        while len(res) < m * n:
            ##开头很麻烦，要统一第一次和接下来的遍历
            for l in range(n-k):
                j += 1
                res.append(matrix[i][j])
            if len(res) == m * n:
                break
            for l in range(m-k-1):
                i += 1
                res.append(matrix[i][j])
            if len(res) == m * n:
                break
            for l in range(n-k-1):
                j -= 1
                res.append(matrix[i][j])
            if len(res) == m * n:
                break
            for l in range(m-k-2):
                i -= 1
                res.append(matrix[i][j])
            ##每次遍历都让圈层减2
            k += 2
        return res
```