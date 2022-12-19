```python
from functools import lru_cache
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        self.res = 0
        arr = [s for s in arr if self.getBinary(s) is not None]
        self.getUniqueSubString(0, arr, 0, 0)
        return self.res
    
    def getUniqueSubString(self, index, arr, num, tmpLength):
        self.res = max(self.res, tmpLength)
        if index == len(arr): return 
        StringBinary = self.getBinary(arr[index])
        self.getUniqueSubString(index + 1, arr, num, tmpLength)
        if StringBinary & num == 0:
            self.getUniqueSubString(index + 1, arr, StringBinary | num, tmpLength + len(arr[index]))
    @lru_cache(None)
    def getBinary(self, s):
        ans = 0
        for ch in s:
            t = ord(ch) - ord('a')
            if (ans & 1 << t) != 0:  return None
            ans |= 1 << t
        return ans
```