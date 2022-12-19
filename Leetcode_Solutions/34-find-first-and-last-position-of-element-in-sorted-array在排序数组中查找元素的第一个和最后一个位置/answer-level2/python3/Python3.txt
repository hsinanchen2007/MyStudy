```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if nums.count(target) == 0:
            return [-1,-1]
        else:
            tar = []
            for i in range(len(nums)):
                if nums[i] == target:
                    tar.append(i)
            return [tar[0],tar[len(tar)-1]]
```
