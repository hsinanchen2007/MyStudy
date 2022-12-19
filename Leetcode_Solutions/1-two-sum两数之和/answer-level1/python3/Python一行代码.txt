```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return [[i, nums[i+1:].index(target-n) + i+1] for i, n in enumerate(nums) if target-n in nums[i+1:]][0]
```
相当于
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, n in enumerate(nums):
            if target-n in nums[i+1:]:
                return [i, nums[i+1:].index(target-n) + i+1]
```
遍历列表，判断满足两数之和这个要求的另一个数是否在列表中，因为可能会有相同值，所以要从当前索引之后开始查找