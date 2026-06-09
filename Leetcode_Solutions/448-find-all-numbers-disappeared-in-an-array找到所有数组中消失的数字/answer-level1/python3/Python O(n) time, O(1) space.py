```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        nums = [0] + nums

        i = 1
        while i < len(nums):
            nextIndex = nums[i]
            while nextIndex != 0:
                tmp = nums[nextIndex]
                nums[nextIndex] = 0
                nextIndex = tmp

            i += 1

        return [i for i,j in enumerate(nums) if j != 0]
```

遍历一遍数组把经过的地方都标记一下，返回没经过的就ok了