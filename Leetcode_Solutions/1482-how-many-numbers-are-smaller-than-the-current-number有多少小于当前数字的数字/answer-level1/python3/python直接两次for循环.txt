### 解题思路
前面如果遇到的话，可以在res里面顺便记录下，节省时间

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: [int]) -> [int]:
        if nums == []:
            return []
        length = len(nums)
        res = [0] * length
        if length == 1:
            return res
        for i in range(length):
            for j in range(i + 1, length):
                if nums[j] < nums[i]:
                    res[i] += 1
                elif nums[j] > nums[i]:
                    res[j] += 1
        return res
```