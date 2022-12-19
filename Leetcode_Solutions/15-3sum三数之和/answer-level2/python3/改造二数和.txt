```
class Solution:
    def threeSum(self, nums: list) -> list:
        nums.sort()
        result,left,min_dic = set(),0,{}
        while left < len(nums) - 2:
            if nums[left] > 0: break
            if nums[left] not in min_dic:
                min_dic[nums[left]] = 1
                if self.twoSum(nums[left+1:], -nums[left]):
                    for tup in self.twoSum(nums[left+1:], -nums[left]):
                        result.add((nums[left], *tup))
            left += 1
        return [list(item) for item in result]

    def twoSum(self, nums:list, target:int):
        result,left,right = set(), 0, len(nums)-1
        while left < right:
            if nums[left] + nums[right] == target:
                result.add((nums[left], nums[right]))
                left += 1
                right -= 1
            elif nums[left] + nums[right] < target:
                left += 1
            else:
                right -= 1
        return result
```
