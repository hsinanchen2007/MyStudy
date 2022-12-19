先排序，把零剔除掉，之后看有没有重复，最大最小值的差有没有超过四（超过4用零补不齐）
```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        while nums and nums[0] == 0:
            nums.pop(0)
        if not nums:
            return True
        return nums[-1] - nums[0] <= 4 and len(set(nums)) == len(nums)
```
