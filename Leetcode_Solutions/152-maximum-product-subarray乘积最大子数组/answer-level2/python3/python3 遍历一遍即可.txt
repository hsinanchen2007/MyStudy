### 解题思路
python3 遍历一遍即可

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        len_nums = len(nums)
        max_val, min_val = nums[0], nums[0]
        ret_max = nums[0]
        for index in range(1,len_nums):
            max_val *= nums[index]
            min_val *= nums[index]

            tmp_list = [nums[index], max_val, min_val]
            tmp_list.sort()
            min_val = tmp_list[0]
            max_val = tmp_list[-1]
            if max_val > ret_max:
                ret_max = max_val

        return ret_max

```