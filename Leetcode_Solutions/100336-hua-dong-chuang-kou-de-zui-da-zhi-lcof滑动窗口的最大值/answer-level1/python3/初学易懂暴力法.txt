### 解题思路
用时5.12%，内存100%

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        r = []
        l = 0
        z = 0
        for i in range(l, len(nums)):
            z = nums[i]
            if l + k > len(nums):
                break
            for j in range(k):
                if z < nums[i + j]:
                    z = nums[i + j]
            r.append(z)
            l = l + 1
        return r
```