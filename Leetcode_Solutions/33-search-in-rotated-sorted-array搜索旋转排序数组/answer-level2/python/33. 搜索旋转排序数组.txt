### 解题思路
看到log(N)时间复杂度应该想到二分法，套模板。
1 2 3 4 5 6 7 的旋转可以分为两类：
- 2 3 4 5 6 7 1 这种，也就是 `nums[left] <= nums[mid]`。此例子中就是 2 <= 5。这种情况下，前半部分有序。因此如果 `nums[left] <=target<nums[mid]`，则在前半部分找，否则去后半部分找。
- 6 7 1 2 3 4 5 这种，也就是 `nums[left] > nums[mid]`。此例子中就是 6 > 2。这种情况下，后半部分有序。因此如果` nums[mid] <target<=nums[right]`，则在后半部分找，否则去前半部分找。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums or len(nums) == 0:
            return -1
        # 套二份查找的模板
        left, right = 0, len(nums)-1
        while left < right:
            mid = left + (right - left)//2
            # 如果前半部分有序
            if nums[mid] >= nums[left]:
                if target >= nums[left] and target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            # 如果后半部分有序
            else:
                if target > nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid

        if nums[left] == target:
            return left
        else:
            return -1



```