```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = nums[0]
        max_move = nums[0]
        for ele in nums[1:]:
            max_move = max(ele,max_move+ele)
            result = max(max_move,result)
        return result
```
