

```
from typing import List
class Solution:

    def dfs(self, i, j, image, m, n, visited, bound):
        if i < 0 or i >= m or j < 0 or j >= n or image[i][j] == '0':
            return

        if (i, j) in visited:
            return

        visited.add((i, j))
        bound[0] = min(bound[0], i)
        bound[1] = max(bound[1], i)
        bound[2] = min(bound[2], j)
        bound[3] = max(bound[3], j)

        for ii, jj in [(i+1, j), (i-1, j), (i, j-1), (i, j+1)]:
            self.dfs(ii, jj, image, m, n, visited, bound)

    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0])

        bound = [0x7fffffff, -0x7fffffff, 0x7fffffff, -0x7fffffff]
        self.dfs(x, y, image, m, n, set(), bound)
        return (bound[1] - bound[0] + 1) * (bound[3] - bound[2] + 1)
```
