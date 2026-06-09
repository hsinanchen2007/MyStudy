```py
class Solution:

    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        direction, total = -1, 0
        ans = []

        while total < m + n - 1:
            start, end = max(total - n + 1, 0), min(total, m-1)
            for i in range(start, end + 1)[::direction]:
                ans.append(matrix[i][total-i])
            direction *= -1
            total += 1

        return ans
```