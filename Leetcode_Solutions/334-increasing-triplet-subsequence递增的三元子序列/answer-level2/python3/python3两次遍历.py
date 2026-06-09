### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:
        # 这个子序列不要求是连续的
        length = len(nums)
        if length < 3:
            return False
        init_num = nums[0]
        add_num = 1
        for i in range(1,length):
            if init_num < nums[i]:
                add_num +=1
                init_num = nums[i]
            if add_num >= 3:
                return True
        init_num = nums[-1]
        add_num = 1
        for i in range(length - 2, -1, -1):
            if init_num > nums[i]:
                add_num += 1
                init_num = nums[i]
            if add_num >= 3:
                return True
        return False
```