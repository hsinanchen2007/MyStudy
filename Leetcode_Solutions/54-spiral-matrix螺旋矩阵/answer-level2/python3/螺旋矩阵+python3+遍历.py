####  方法1：直接遍历

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|   O(mn)    |   O(mn)    |

**基本思路：**

> 按题意遍历输出。

**代码：**

```python []
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])  # 行，列

        # 1. 横向遍历m，纵向遍历n-1；
        # 2. 横向遍历m-1，纵向遍历n-2；
        # 3. 横向遍历m-2，纵向遍历n-3；
        # 4. 直到有一方向遍历长度为0时终止。

        ans = []
        judge = 1     # 1为顺序遍历，-1为逆序遍历
        i, j = 0, -1  # 初始位置，列为-1，因为代表[0,0]前一个位置
        while m > 0 and n > 0:

            # 横向遍历
            for x in range(n):
                j += judge * 1
                ans.append(matrix[i][j])

            # 纵向遍历
            for y in range(m - 1):
                i += judge * 1
                ans.append(matrix[i][j])

            m, n = m - 1, n - 1
            judge *= -1

        return ans
```