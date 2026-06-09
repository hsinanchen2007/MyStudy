### 解题思路
从左向右，第i次的最优选择都是  第i-2或i-3中的最优解 + 第i次的值

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 1:
            return nums[0]
        elif l == 0:
            return 0
        s = [0,0] + nums
        for i in range(3, l+2):
            s[i] += max(s[i - 2],s[i - 3])
        if s[-1] > s[-2]:
            return s[-1]
        else:
            return s[-2]

```