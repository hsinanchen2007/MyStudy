

# ### 代码

# ```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        nums.sort()
        return nums[len(nums)//2]
# ```