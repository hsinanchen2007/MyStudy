```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # only contain a, b, c
        # a, b, c => 1
        # a, b, c, a => 2
        # contongious string
        # Sliding window 
        # Time complexity: O(N)
        # Space complexity: O(1)
        cntArr = [0] * 3
        res, l = 0, 0

        def putChar(ch):
            cntArr[ord(ch) - ord("a")] += 1
        def minusChar(ch):
            cntArr[ord(ch) - ord("a")] -= 1
            return cntArr[ord(ch) - ord('a')]

        for i, ch in enumerate(s):
            putChar(ch)
            if  all(cntArr):
                res += len(s) - i
                while True:
                    if not minusChar(s[l]):
                        l += 1
                        break
                    l += 1
                    res += len(s) - i
        return res
```