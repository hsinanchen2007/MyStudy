借助numpy, scipy


```
import numpy as np
from scipy.signal import convolve2d

class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        return np.max(convolve2d(A, np.rot90(B, 2)))
```

或者更简洁:
```
from scipy.signal import correlate2d

class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        return correlate2d(A, B).max()
```
