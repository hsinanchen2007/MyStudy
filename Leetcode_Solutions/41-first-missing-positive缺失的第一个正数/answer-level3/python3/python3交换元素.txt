### 解题思路
python3交换

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        len_nums = len(nums)
        index = 0
        if not nums:
            return 1
        while index < len_nums:
            if nums[index] > 0 and nums[index] < len_nums+1:
                target_index = nums[index]-1
                if nums[index] == index + 1 or (nums[target_index] == target_index + 1):
                    #souce or target is ok
                    index += 1
                else:
                    nums[index], nums[target_index] = nums[target_index], nums[index]
            else:
                index += 1

        for index in range(len_nums):
            if index+1 != nums[index]:
                return (index+1)

        return index+2
```