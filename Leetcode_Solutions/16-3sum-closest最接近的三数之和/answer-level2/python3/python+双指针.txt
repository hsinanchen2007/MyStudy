固定一个，再使用双指针法
```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        panduan = float('inf')
        ans = 0
        for k in range(len(nums)):
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            i = k + 1
            j = len(nums) - 1
            while i < j:
                r = nums[k] + nums[i] + nums[j]
                m = abs(r - target)
                if m < panduan:
                    panduan = m
                    ans = r
                if r < target:
                    i += 1
                    while i < j and nums[i] == nums[i - 1]:i += 1
                elif r > target:
                    j -= 1
                    while i < j and nums[j] == nums[j + 1]:j -= 1
                elif r == target:
                    return r
        return ans
```
