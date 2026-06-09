### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        n = length - k + 1
        out = []
        for i in range(n):
            temp = max(nums[i:i+k])
            out.append(temp)
        return out
```