####  方法1：直接遍历

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|   O(n^2)   |   O(n^2)   |

**基本思路：**

> 根据题意直接遍历

**代码：**

```python []
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:

        # 生成初始矩阵
        matrix = [[0 for i in range(n)] for i in range(n)]

        i, j = 0, -1
        p, q = n, n
        tmp = 1
        judge = 1

        while p > 0 and q > 0:

            for x in range(q):
                j += 1 * judge
                matrix[i][j] = tmp
                tmp += 1

            for y in range(p - 1):
                i += 1 * judge
                matrix[i][j] = tmp
                tmp += 1
            p, q = p - 1, q - 1
            judge *= -1

        return matrix
```