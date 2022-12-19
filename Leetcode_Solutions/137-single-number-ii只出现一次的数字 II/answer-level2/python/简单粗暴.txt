### 解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        while True:
            a = nums[0]
            nums.remove(a)
            if a not in nums:
                return a
            nums.append(a)
```