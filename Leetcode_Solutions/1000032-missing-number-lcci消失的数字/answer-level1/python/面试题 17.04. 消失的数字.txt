### 解题思路
首先统计0 - n所有元素的和，然后依次减去每个元素

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum = n*(n+1) >> 1
        for i in nums:
            sum -= i
        return sum
```