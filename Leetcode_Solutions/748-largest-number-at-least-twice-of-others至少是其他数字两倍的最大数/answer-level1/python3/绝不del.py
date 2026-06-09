```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
      l=len(nums)
      if l>1:
        s=max(nums)
        ind=nums.index(s)
        nums.remove(s)
        if s>=(max(nums)*2):
          return ind
        else:
          return -1
      else:
        return 0

```