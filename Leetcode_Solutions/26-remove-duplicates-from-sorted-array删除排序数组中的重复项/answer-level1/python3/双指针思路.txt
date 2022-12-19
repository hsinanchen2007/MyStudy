### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        else:
            left_index = 0
            cur_index = 1
            tmp = nums[0]
            while cur_index < len(nums):
                if nums[cur_index] == tmp:
                    cur_index += 1
                else:
                    nums[left_index+1],nums[cur_index] = nums[cur_index],nums[left_index+1]
                    left_index += 1
                    tmp = nums[left_index]
                    cur_index += 1
            return left_index+1
```