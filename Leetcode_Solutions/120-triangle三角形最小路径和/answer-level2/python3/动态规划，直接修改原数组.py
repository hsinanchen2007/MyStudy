直接原地修改原数组。

```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for i in range(n):
            for j in range(i+1):
                if i >= 1:
                    if j == 0:
                        triangle[i][j] += triangle[i-1][j]
                    elif j == i:
                        triangle[i][j] += triangle[i-1][j-1]
                    else:
                        triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
        return min(triangle[-1])
```

也可以不改变原数组，利用一个数组存储上一行各位置的最小路径。

```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        res = triangle[0]
        for i in range(1, n):
            tmp = res.copy()
            res += [res[-1]]
            for j in range(i+1):
                    if j == 0:
                        res[j] = tmp[j] + triangle[i][j]
                    elif j == i:
                        res[j] = tmp[-1] + triangle[i][j]
                    else:
                        res[j] = min(tmp[j-1], tmp[j]) + triangle[i][j]
        return min(res)
```