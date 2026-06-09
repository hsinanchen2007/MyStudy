### 解题思路
最开始也是各种超时，尽可能减少循环

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []

        length = len(nums) 
        for k in range(length):
            i = length - 1
            if nums[k] > 0:
                break
            if k > 0 and nums[k] == nums[k-1]:
                continue
            if nums[k] + nums[i] + nums[i-1] < 0:
                continue

            j = k + 1
            while i > j:
                summary = nums[k] + nums[i] + nums[j]
                if summary > 0:
                    i -= 1
                elif summary < 0:
                    j += 1
                else:
                    result.append([nums[k], nums[j], nums[i]])
                    while j < i and nums[j] == nums[j+1]:
                        j += 1
                    while i > j and nums[i] == nums[i-1]:
                        i -= 1
                    j += 1
                    i -= 1

        return result
        
```