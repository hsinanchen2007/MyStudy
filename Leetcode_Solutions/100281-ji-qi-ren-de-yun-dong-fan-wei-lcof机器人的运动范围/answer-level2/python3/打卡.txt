### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def sum_ij(row, col):
            ans = 0
            for i in range(len(str(row))):
                ans += row % 10
                row //= 10
            for j in range(len(str(col))):
                ans += col % 10
                col //= 10
            return ans
                
        from collections import deque
        queue = deque()
        queue.append((0,0))
        marked = set()
        while queue:
            i, j = queue.popleft()
            if (i, j) not in marked and sum_ij(i, j) <= k:
                marked.add((i, j))
                for (di, dj) in [(1, 0), (0, 1)]:
                    if 0 <= i + di < m and 0 <= j + dj < n:
                        queue.append((i + di, j + dj))
        return len(marked)
```