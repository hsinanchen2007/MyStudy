

```python []
class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        l, r, t, d = 0, 0, 0, {}
        for i, c in enumerate(array):
            if t not in d:
                d[t] = i
            if i - d[t] > r - l:
                l, r = d[t], i
            t += c.isdigit() or -1
        if t in d and len(array) - d[t] > r - l:
            l, r = d[t], len(array)
        return array[l: r]
```