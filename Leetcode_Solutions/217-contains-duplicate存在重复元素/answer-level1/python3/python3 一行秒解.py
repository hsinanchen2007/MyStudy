# ### 代码

# ```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(list(set(nums)))!=len(nums)
# ```