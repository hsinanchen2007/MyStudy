```
import heapq as hq
class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        row, col = len(A), len(A[0])
        ans = [(-A[0][0], 0, 0)]
        A[0][0] = -1
        hq.heapify(ans)
        while ans:
            score, i, j = hq.heappop(ans)
            if (i, j) == (row - 1, col - 1):
                return -score
            for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                new_i = i + di
                new_j = j + dj
                if 0 <= new_i < row and 0 <= new_j < col:
                    if A[new_i][new_j] != -1:
                        hq.heappush(ans, (max(score, -A[new_i][new_j]), new_i, new_j))
                        A[new_i][new_j] = -1
```
