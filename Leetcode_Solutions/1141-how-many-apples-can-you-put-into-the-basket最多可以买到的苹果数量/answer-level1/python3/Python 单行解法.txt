```
from itertools import takewhile, accumulate

class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        return len(list(takewhile(lambda x: x <= 5000, accumulate(sorted(arr)))))
```
