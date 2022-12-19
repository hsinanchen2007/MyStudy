### 解题思路
没啥好说的，就是简单的模拟，四个边界依次往里缩。处理下标很烦，要胆大心细。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix):
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        if n == 0:
            return []

        l, r, u, d = 0, n-1, 0, m-1
        nowm, nown = 0, -1
        ans = []

        while True:
            nown += 1
            for i in range(nown, r+1):
                ans.append(matrix[nowm][i])
            u += 1
            nown = r

            if len(ans) == m * n:
                return ans

            nowm += 1
            for i in range(nowm, d+1):
                ans.append(matrix[i][nown])
            nowm = d
            r -= 1

            if len(ans) == m * n:
                return ans

            nown -= 1
            for i in range(nown, l-1, -1):
                ans.append(matrix[nowm][i])
            d -= 1
            nown = l

            if len(ans) == m * n:
                return ans

            nowm -= 1
            for i in range(nowm, u-1, -1):
                ans.append(matrix[i][nown])
            l += 1
            nowm = u

            if len(ans) == m * n:
                return ans
```