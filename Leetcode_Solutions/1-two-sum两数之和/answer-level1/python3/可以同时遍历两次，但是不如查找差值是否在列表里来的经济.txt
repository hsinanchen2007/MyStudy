### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, nums, target) :
        lenth = len(nums)
        for i in range(lenth):
            #余数
            gap = target - nums[i]
            #看看有没和自己一样的值
            indices = [index for index, value in enumerate(nums) if value==gap]
            if indices:
                for index in indices:
                    if index != i:
                        return [i, index]

```