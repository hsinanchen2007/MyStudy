### 解题思路
把所给列表分割为两部分，若目标值减去当前索引索引值存在于列表中则将列表分割为:nums[0:i]和nums[i+1:] 
第一个索引值即为当前索引值，第二个索引值为当前索引值加一再加上目标差值在在分割后的列表中的索引值

### 代码

```python3
class Solution:
    def twoSum(self, nums, target):
        i = 0
        result = [0,0]
        while i < len(nums):
            if(target - nums[i]) in nums[i+1:]:
                result[0] = i
                result[1] =  i + 1 + nums[i+1:].index(target - nums[i])
                return result
            else:
                i +=1
        return

                    
```