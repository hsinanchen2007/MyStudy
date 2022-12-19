### 解题思路
**投票法
**
### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        cur = nums[0]
        count = 1
        for i in range(1,len(nums)):
            if nums[i] == cur:
                count += 1
            else:
                count -= 1
            if count == 0:
                cur = nums[i]
                count = 1
        return cur
```