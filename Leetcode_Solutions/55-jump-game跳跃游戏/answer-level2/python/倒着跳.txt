### 解题思路
如果nums[-2]能跳到nums[-1]，那么问题就变成了nums[-2]之前的元素能否跳到nums[-2]。

从后向前类推，一但有一个元素不能被它前面的元素跳到，说明跳跃出现断层。

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        distance = -1
        for i in reversed(range(len(nums))):
            distance += 1
            if nums[i] >= distance:
                distance = 0
        if distance > 0:
            return False
        return True
```