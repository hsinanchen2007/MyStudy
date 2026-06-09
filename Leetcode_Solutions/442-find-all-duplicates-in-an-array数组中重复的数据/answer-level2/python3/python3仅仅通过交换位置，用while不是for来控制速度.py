### 解题思路
python3仅仅通过交换位置，用while不是for来控制速度

### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        len_int_list = len(nums)
        if len_int_list < 2:
            return []

        ret_list = []
        index = 0
        while index < len_int_list:
            if (index+1) != nums[index]:
                if nums[index] != nums[nums[index]-1]:
                    target_index = nums[index]-1
                    nums[index], nums[target_index] = nums[target_index], nums[index]
                else:
                    ret_list.append(nums[index])
                    index += 1
            else:
                index += 1

        return list(set(ret_list))

```