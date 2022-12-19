### 解题思路
用index会比较方便，运行会稍稍慢一点点
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return nums.index(target) if target in nums else sorted(nums + [target]).index(target)
```