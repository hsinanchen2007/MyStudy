```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        # two pointers
        ans = 0
        l, r, cnt = None, 0, 0
        while r < len(nums):
            if nums[r] & 1: 
                if l is None: l = r
                cnt += 1
                if cnt == k or ans != 0:
                    tempL, tempR = l - 1, r + 1
                    while tempL >= 0 and nums[tempL]  & 1 == 0: tempL -= 1
                    while tempR < len(nums) and nums[tempR] & 1 == 0 : tempR += 1
                    ans += (l - tempL) * (tempR - r)    
                    r = tempR
                    l = l + 1
                    while l < len(nums) and nums[l] & 1 == 0: l += 1
            if ans == 0:
                r += 1
        return ans
```