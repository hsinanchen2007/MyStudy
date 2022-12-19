### 解题思路
此代码中修改了一个元素，但是如果临时保存的话，原数组就不会修改

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return True

        modified = False

        for index in range(1, len(nums)):
            if nums[index - 1] <= nums[index]:
                pass
            else:
                if modified:
                    return False

                modified = True

                if index >= 2 and nums[index - 2] > nums[index]:
                    nums[index] = nums[index - 1]

        return True
```