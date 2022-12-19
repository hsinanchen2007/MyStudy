整个过程类似于杨辉三角，让下一行的每一个数加上上一行所能加的最小数，两边边界直接加上上一行的边界值。
可以在原数组上直接修改，无需任何多余的空间消耗。
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0
        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        triangle[1][0] += triangle[0][0]
        triangle[1][1] += triangle[0][0]
        for i in range(2,n):
            for j in range(1,i):
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j])
            triangle[i][0] += triangle[i-1][0]
            triangle[i][-1] += triangle[i-1][-1]
        return min(triangle[-1])
```
