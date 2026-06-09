```python
class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        # Time complexity : O(N ** 2)
        # Space complexity : O(1)
        # Two pointers
        nums.sort() # O(NlogN)
        def get_cnt(left, right, target): # Time complexity : O(N)
            res = 0
            while left < right:
                val = nums[left] + nums[right]
                if val < target:
                    res += right - left
                    left += 1
                else:
                    right -= 1
            return res 
                  
        ans = 0
        for i in range(len(nums) - 2):
           ans += get_cnt(i + 1, len(nums) - 1, target - nums[i])
        return ans
```