# ### 代码

# ```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return int((3 * sum(set(nums)) - sum(nums)) / 2)
# ```