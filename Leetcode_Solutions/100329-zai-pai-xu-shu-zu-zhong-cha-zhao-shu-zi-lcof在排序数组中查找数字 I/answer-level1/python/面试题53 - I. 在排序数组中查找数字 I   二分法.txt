### 解题思路
此题遍历即可得到结果，但是考虑到有序数组所以选择二分法

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1
        count = 0
        while left <= right:
            mid = left + (right - left)//2
            if nums[mid] == target:
                r = mid + 1
                l = mid - 1
                count += 1
                while l >= 0:   #判断 mid 前后是否 = target
                    if nums[l] == target:
                        count += 1
                        l -= 1
                    else:
                        break
                while r < len(nums):
                    if nums[r] == target:
                        count += 1
                        r += 1
                    else:
                        break
                return count
            elif nums[mid] > target:
                right = mid -1
            elif nums[mid] < target:
                left = mid + 1
        return count
```