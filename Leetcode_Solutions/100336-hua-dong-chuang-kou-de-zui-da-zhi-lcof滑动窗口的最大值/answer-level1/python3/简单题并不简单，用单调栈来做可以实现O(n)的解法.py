### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        l, r = 0, 0
        res,stack = [],[]
        while r < k:
            while stack and nums[r] > nums[stack[-1]]:
                stack.pop()
            stack.append(r)
            r += 1
        r -= 1
        while r < len(nums):
            res.append(nums[stack[0]])
            l += 1
            r += 1
            if r == len(nums):
                return res
            while stack and nums[r] > nums[stack[-1]]:
                stack.pop()
            stack.append(r)
            while l > stack[0]:
                stack.pop(0)
        return res


```