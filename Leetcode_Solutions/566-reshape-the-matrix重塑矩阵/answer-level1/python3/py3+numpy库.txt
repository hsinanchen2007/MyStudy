直接使用numpy库，加一个try语句搞定，感觉有点投机了(⊙ˍ⊙)
```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        import numpy as np
        try:
            nums = np.array(nums).reshape(r,c)
            l = []
            for i in range(r):
                l.append(list(nums[i]))
            return l
        except ValueError:
            return nums
        
```
