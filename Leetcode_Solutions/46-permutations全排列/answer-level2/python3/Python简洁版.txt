```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.r = []
        self.xun([], nums)
        return self.r

    def xun(self, tmp, nums):
        if len(tmp) == len(nums):
            self.r.append(tmp)
            return
        for i in nums:
            if i not in tmp:
                self.xun(tmp + [i], nums)
```
