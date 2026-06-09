```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if not n:
            return []
        res = [[0 for i in range(n)] for j in range(n)]
        left = 0
        right = n - 1
        top = 0
        down = n - 1
        num = 1
        while left <= right and top <= down:
            for i in range(left, right+1):
                res[top][i] = num
                num += 1
            top += 1
            for i in range(top, down+1):
                res[i][right] = num
                num += 1
            right -= 1
            for i in range(right, left-1, -1):
                res[down][i] = num
                num += 1
            down -= 1
            for i in range(down, top-1, -1):
                res[i][left] = num
                num += 1
            left += 1
        return res

```
