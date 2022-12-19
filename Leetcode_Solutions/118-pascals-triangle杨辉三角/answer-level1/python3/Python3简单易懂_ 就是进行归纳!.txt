### 解题思路
这种题没啥特别, 就是要归纳
i = 0, j = 0, A[0][0] = 1
i = 1, j = 0 ~ 1, ...
i = 2, j = 0 ~ 2, A[2][1] = A[1][0] + A[1][1]
可以得到通用表达式: A[i][j] = A[i - 1][j - 1] + A[i - 1][j]
为了简化代码, 我们增加一个get_val函数, 能够处理j < 0 和 j > i的超出边界情况.
那么, 我们就有 A[2][0] = A[1][-1] + A[1][0]; A[2][2] = A[1][1] + A[1][2], 其中A[1][-1]和A[1][2]都属于超出边界的情况, get_val会返回0

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        def get_val(A, i, j):
            if i < 0:
                return 0
            if j < 0 or j > i:
                return 0
            # j = 0 ~ i
            return A[i][j]

        if numRows == 0:
            return []
        A = []
        for i in range(numRows):
            row = [1] * (i + 1)
            if i != 0:
                for j in range(i + 1):  
                    row[j] = get_val(A, i - 1, j - 1) + get_val(A, i - 1, j)
            A.append(row)
        return A
```