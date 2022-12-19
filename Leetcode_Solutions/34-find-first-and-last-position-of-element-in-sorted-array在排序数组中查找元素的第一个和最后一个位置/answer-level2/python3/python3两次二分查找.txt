### 解题思路
python3两次二分查找

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ret_list = [-1, -1]
        len_nums = len(nums)

        if len_nums < 2:
            if target in nums:
                return [0, 0]

        left = 0
        right = len_nums - 1
        while left < right:
            mid = (left+right)//2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if nums and nums[left] == target:
            ret_list[0] = left
            right = len_nums - 1
            while left < right:
                mid = (left+right+1)//2
                if nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid
            ret_list[1] = right

        return ret_list

```