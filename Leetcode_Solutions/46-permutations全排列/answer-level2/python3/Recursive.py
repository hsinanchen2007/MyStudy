```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 1: return [nums]
        result = []
        for index in range(len(nums)):
            for temp_list in self.permute(nums[:index] + nums[index + 1:]):
                result.append([nums[index]] + temp_list)
        return result

        
```
