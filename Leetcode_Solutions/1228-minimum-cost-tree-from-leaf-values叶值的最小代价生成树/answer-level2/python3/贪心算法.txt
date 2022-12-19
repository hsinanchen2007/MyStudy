```python
class Solution:
    def min_idx(self, ls):
        idx = 0
        for i, x in enumerate(ls):
            if x < ls[idx]:
                idx = i
        return idx
        
    def mctFromLeafValues(self, arr: List[int]) -> int:
        ans = 0
        while len(arr) > 1:
            mutil = [x*y for x, y in zip(arr[:-1], arr[1:])]
            idx = self.min_idx(mutil)
            ans += mutil[idx]
            arr[idx:idx+2] = [max(arr[idx:idx+2])]
        return ans
```