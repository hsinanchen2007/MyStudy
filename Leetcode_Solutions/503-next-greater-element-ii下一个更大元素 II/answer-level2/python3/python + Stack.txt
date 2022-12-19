```python
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # Time complexity : O(N)
        # Space complexity: O(N)
        res = [-1] * len(nums)
        stack = []
        for i, num in enumerate(nums):
            while stack and num > nums[stack[-1]]:
                res[stack[-1]] = num
                stack.pop()
            stack.append(i)
        for i, num in enumerate(nums):
            if stack and i == stack[-1]: break
            while stack and num > nums[stack[-1]]:
                res[stack[-1]] = num
                stack.pop()
        return res
```