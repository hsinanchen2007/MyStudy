### 解题思路
此处撰写解题思路

### 代码

```python3
from typing import List


class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        left, right, now = m - 1, n - 1, m + n - 1
        while now >= 0:
            if right < 0 or (left >= 0 and A[left] > B[right]):
                A[now] = A[left]
                left -= 1
            else:
                A[now] = B[right]
                right -= 1
            now -= 1

```