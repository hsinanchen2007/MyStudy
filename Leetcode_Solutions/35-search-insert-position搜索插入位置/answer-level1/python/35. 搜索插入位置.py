### 解题思路
因为是有序数组，所以最快的方法是二分法

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) -1
        while True:
            index = int((left + right)/2)
            # print(left, right, index)
            if target > nums[index]:
                left = index
            else:
                right = index

            # print(left, right, index)
            # print('*' * 20)
            if len(nums[left: right])<=1:
                if target > nums[left] and target <= nums[right]:
                    rt = right
                elif target > nums[right]:
                    rt = right + 1
                elif target <= nums[left]:
                    rt = left
                break
        return rt
```