### 解题思路
倒序遍历，只判断两头的元素，中间元素可以忽略，若相同说明前后中是同一个数字，就删除最后一个，继续遍历。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        for i in range(len(nums) - 1 , 1 , -1):
            if nums[i] == nums[i-2]:
                nums.pop(i)
        return len(nums)

        # i = 1
        # k = i - 1 
        # j = i + 1
        # while j < len(nums):
        #     if nums[i] != nums[j] or (nums[i] == nums[j] and nums[j] != nums[k]):
        #         k = i
        #         nums[i+1] = nums[j]
        #         i += 1
        #     j += 1                
        # return i + 1
```