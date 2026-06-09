### 解题思路
逐层遍历后判断邻域点是否满足条件，进行进一步运算

### 代码

```python3
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        x, y = len(M), len(M[0])
        ans = [[0 for i in range(y)] for j in range(x)]
        for i in range(x):
            for j in range(y):
                sum_ = count = 0
                for ni in (i - 1, i, i + 1):
                    for nj in (j - 1, j, j + 1):
                        if (0 <= ni < x and 0 <= nj < y):
                            sum_ += M[ni][nj]
                            count += 1
                ans[i][j] = math.floor(sum_ / count)
        return ans
```