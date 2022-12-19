### 解题思路
1. 遍历，可以将特殊情况直接提出来
2. 二分查找

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # if target > nums[-1]:
        #     return len(nums)
        # if target < nums[0]:
        #     return int(0)
        # if target in nums:
        #     return nums.index(target)
        # else:
        #     for i in range(0, len(nums) - 1):
        #         if nums[i] < target and nums[i+1] > target:
        #             return i + 1

        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return int(0)
        right = 0
        left = len(nums) -1
        while right < left:
            mid = (right+left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                right += 1
            else:
                left -= 1
        return right

```