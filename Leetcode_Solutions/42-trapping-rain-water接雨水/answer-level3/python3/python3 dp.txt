```
class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = [0] * len(height), [0] * len(height)
        cur_max = 0

        for i, h in enumerate(height):
            left[i] = max(0, cur_max - h)
            cur_max = max(cur_max, h)
        
        cur_max = 0
        for i, h in enumerate(height[::-1]):
            right[len(right)-1-i] = max(0, cur_max-h)
            cur_max = max(cur_max, h)
        

        return sum([min(l,r) for l, r in zip(left, right)])
```
