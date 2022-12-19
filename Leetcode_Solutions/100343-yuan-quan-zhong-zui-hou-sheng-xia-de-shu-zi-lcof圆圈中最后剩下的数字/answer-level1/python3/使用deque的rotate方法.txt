### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import deque
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
      d = deque(range(n))
      while len(d) != 1:
        d.rotate(-(m-1))
        d.popleft()
      return d[0]

```