### 解题思路
此处撰写解题思路
首先判断列表是否为空，不是的话继续

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == 0:
            return []
        if 1 <= k <= len(nums):
            index = 0
            res = []
            while index <= len(nums)-k:
                res.append(max(nums[index: (index+k)]))
                index += 1
            return res
        else:
            return [max(nums)]
```