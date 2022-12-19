先根据左边界还是右边界好改变决定选择左中位数还是右中位数
while条件中不要有=
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        len_nums = len(nums)
        if len_nums == 0:
            return -1

        low_index = 0
        high_index = len(nums) - 1

        while low_index < high_index:
            mid_index = (low_index + high_index)//2
            if nums[mid_index] < nums[high_index]:
                #spin little
                if target <= nums[high_index] and target > nums[mid_index]:
                    low_index = mid_index+1
                else:
                    high_index = mid_index
            else:
                #spin large
                if target <= nums[mid_index] and target >= nums[low_index]:
                    high_index = mid_index
                else:
                    low_index = mid_index+1                    

        if nums[low_index] == target:
            return low_index
        else:
            return -1

```
