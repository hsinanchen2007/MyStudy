### 解题思路
基于哈希表

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        _target = []
        for i in range(len(nums)):
            try:
                return[_target.index(nums[i]), i]
            except:
                _target.append(target-nums[i])
```