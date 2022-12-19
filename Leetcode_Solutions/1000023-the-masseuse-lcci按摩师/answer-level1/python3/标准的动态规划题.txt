### 解题思路
状态s[i]表示以nums[i]作为最后一个值时的输出，也就是s[i] = max(s[i-2]+nums[i], s[i-3]+nums[i])
最后的输出应该是s[i],s[i-1]中的较大者。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        # s[i]表示选择i作为最后结束的数
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        if len(nums) == 3:
            return max(nums[0]+nums[2], nums[1])
        
        s = [0] * len(nums)
        for i in range(0, len(nums)):
            if i == 0:
                s[0] = nums[0]
            if i == 1:
                s[1] = nums[1]
            if i == 2:
                s[2] = nums[0] + nums[2]
            else:
                s[i] = max(s[i-2]+nums[i], s[i-3]+nums[i])
        
        return max(s[-2], s[-1])

```