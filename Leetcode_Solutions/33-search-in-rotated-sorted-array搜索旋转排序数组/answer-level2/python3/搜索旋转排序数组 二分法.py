### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了96.22%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.15%的用户

思路：两次二分法
1. 第一次找到数组是从哪里旋转的，也就是找到数组中最小的元素
2. 锁定在左半部分还是右半部分寻找目标值，确定初始left和right，寻找目标值

### 代码

```python3
class Solution:
    def search_min_value(self, nums):
        print(nums)
        if nums[0] < nums[-1]:
            return 0

        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[mid+1]:
                return mid+1
            elif nums[mid] >= nums[0]:
                left = mid + 1
            elif nums[mid] < nums[0]:
                right = mid - 1

        return -1




    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        if len(nums) == 1:
            if target == nums[0]:
                return 0
            else:
                return -1

        min_index = self.search_min_value(nums)

        if min_index == 0:
            left = 0
            right = len(nums) - 1
        elif target < nums[0]:
            left = min_index
            right = len(nums) - 1
        else:
            left = 0
            right = min_index - 1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1

        return -1
```