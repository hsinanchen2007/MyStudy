```python
import datetime
from itertools import permutations

class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        time = []
        for perm in permutations(A, 4):
            try:
                time.append(datetime.time(
                    int(str(perm[0]) + str(perm[1])), 
                    int(str(perm[2]) + str(perm[3]))
                   ))
            except:
                continue
        return max(time).isoformat()[:5] if time else ""
```
用python的标准库求解