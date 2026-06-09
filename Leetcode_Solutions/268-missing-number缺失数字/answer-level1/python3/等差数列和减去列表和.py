### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: [int]) -> int:
        # 这个要求线性的时间复杂度和常数的额外空间，也就是说我弄个字典来查是不行的
        # 我的想法是用和，应该的和减去列表数的和，就知道是缺了哪个了
        # 等差数列和首项加末项乘以项数除以二
        n = len(nums)
        if n == 0:
            return None
        ShouldSum = n *(1 + n) / 2
        NumsSum = sum(nums)
        return int(ShouldSum - NumsSum)
```