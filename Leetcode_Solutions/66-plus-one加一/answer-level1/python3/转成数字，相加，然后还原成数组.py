### 解题思路
时间复杂度：O（n）
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) < 1:
            return 1
        nums = 0
        for i in digits:
            nums *= 10
            nums += i
        nums += 1
        out_nums = []
        while nums > 0:
            m, n = divmod(nums, 10)
            out_nums.append(n)
            nums = m
        return out_nums[::-1]

```