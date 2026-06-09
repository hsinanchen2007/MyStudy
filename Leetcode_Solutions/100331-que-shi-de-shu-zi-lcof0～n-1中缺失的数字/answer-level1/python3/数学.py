### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l = len(nums)
        sum1 = l * (l + 1) / 2
        return int(sum1 - sum(nums))

```