```python
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        if nums == []: return []
        res = [-1] * len(nums)
        stack = []
        cur, loopCur = 0, 2 * len(nums) - 1
        while loopCur > 0:
            while stack and nums[cur] > nums[stack[-1]]:
                index = stack.pop()
                res[index] = nums[cur]
            if stack and cur == stack[-1]: break
            stack.append(cur)
            cur = (cur + 1) % len(nums)
            loopCur -= 1
        return res

```