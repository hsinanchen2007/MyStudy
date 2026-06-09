```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        seen = set()
        count = 0
        directions = [(0,1), (0, -1), (1, 0), (-1, 0)]
        def getCount(num:int):
            numCount = 0
            while num > 0:
                numCount += num % 10
                num = num // 10
            return numCount
        def dfs(row:int, col:int):
            nonlocal count
            # 不符合状态
            if not (0 <= row < m and 0 <= col < n):
                return
            if (row, col) in seen:
                return
            else:
                seen.add((row, col))
            rowCount = getCount(row)
            colCount = getCount(col)
            if rowCount + colCount <= k:
                count += 1
                for deltaX, deltaY in directions:
                    dfs(row + deltaX, col + deltaY)
        dfs(0, 0)
        return count
```