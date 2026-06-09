### 解题思路
将集合有序排列，与题对应，返回长度即可
92ms14.4mb

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nus = sorted(list(set(nums)))
        for i in range(len(nus)):
            nums[i] = nus[i]
        return len(nus)
```