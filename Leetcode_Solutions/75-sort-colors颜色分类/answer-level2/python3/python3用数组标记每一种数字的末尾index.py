### 解题思路
python3用数组标记每一种数字的末尾index

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return nums
        end_index_list = [-1, -1, -1]

        len_nums = len(nums)
        end_index_list[nums[0]] = 0
        index = 1
        while index < len_nums:
            # import ipdb; ipdb.set_trace()
            if nums[index] < nums[index-1]:
                target_index = end_index_list[nums[index]]+1
                nums[index], nums[target_index] = nums[target_index], nums[index]
                if nums[index] == nums[index-1]:
                    end_index_list[nums[index]] = index
                end_index_list[nums[target_index]] = target_index
            else:
                end_index_list[nums[index]] = index
                index += 1

            if end_index_list[1] < end_index_list[0]:
                end_index_list[1] = end_index_list[0]
            if end_index_list[2] < end_index_list[1]:
                end_index_list[2] = end_index_list[1]

        return nums


```