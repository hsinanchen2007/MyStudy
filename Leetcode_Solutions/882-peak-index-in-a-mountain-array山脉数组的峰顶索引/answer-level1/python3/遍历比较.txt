### 解题思路
............

### 代码

```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        for i in range(len(A)-1):
            if A[i]>=A[i+1]:
                return i
```