### 解题思路
如果target是比nums最大的数还大. 直接返回列表长度
如果不是,就循环列表. 

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target > nums[-1]:
            return len(nums)
        else:
            cur = 0
            while cur < len(nums):
                if target <= nums[cur]:
                    return cur
                else:
                    cur += 1
```