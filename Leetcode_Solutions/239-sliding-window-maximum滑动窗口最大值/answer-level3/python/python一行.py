### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        return [max(nums[i:i+k]) for i in range(len(nums)-k+1)] if  nums else []
```