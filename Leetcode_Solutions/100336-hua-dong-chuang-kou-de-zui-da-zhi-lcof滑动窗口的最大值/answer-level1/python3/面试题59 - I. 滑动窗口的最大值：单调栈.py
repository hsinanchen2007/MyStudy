### 解题思路
单调栈

### 代码

```python []
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        s = collections.deque()
        for i, num in enumerate(nums, 1):
            while s and num > s[-1]:
                s.pop()
            s.append(num)
            if i >= k:
                yield s[0]
                if nums[i - k] == s[0]:
                    s.popleft()
```