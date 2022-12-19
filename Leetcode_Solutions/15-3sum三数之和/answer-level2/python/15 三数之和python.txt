### 解题思路
固定一个值，找另外二个值它们和等于 0，
如何找另外两个值，用的是双指针！

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        len_nums = len(nums)
        res = []

        for i in range(len_nums):
            left = i + 1
            right = len_nums - 1
            if i > 0 and nums[i]==nums[i-1]:
                continue
            if nums[i] > 0:
                break
            while left < right:
                cal_val = nums[i] + nums[left] + nums[right]
                if cal_val == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left]==nums[left+1]:
                        left += 1
                    while left < right and nums[right]==nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif cal_val > 0:
                    right -= 1
                elif cal_val < 0:
                    left += 1
            
        return res

            

            



```